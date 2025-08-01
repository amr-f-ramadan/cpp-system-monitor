#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
#include "linux_parser.h"

using std::stof;
using std::stoi;
using std::string;
using std::to_string;
using std::vector;


// A template function to get the value in a file (in case of a multi-line-file)
template <typename T>
T findValueByKey(std::string const &keyFilter, std::string const &filename, int whichValue = 1, vector<vector<char>> replaces = {}) {
  string line, key;
  T value;

  std::ifstream stream(filename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      for (auto replace : replaces) {
        std::replace(line.begin(), line.end(), replace[0], replace[1]);
      }
      std::istringstream linestream(line);
      if (linestream >> key && key == keyFilter) {
        for (int i = 0; i < whichValue; i++) {
          linestream >> value;
        }
        return value;
      }
    }
  }
  return value;
} 

// A template function to get the value in a file (in case of a single-line-file)
template <typename T>
T getValueOfFile(string const &filename, int whichValue = 1) {
  string line;
  T value;

  std::ifstream stream(filename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < whichValue; i++) {
      linestream >> value;
    }
  }
  return value;
}

// An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string OS = findValueByKey<string>("PRETTY_NAME", kOSPath, 1, {{' ', '_'}, {'=', ' '}, {'"', ' '}});
  std::replace(OS.begin(), OS.end(), '_', ' ');
  return OS;
}

// An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  return getValueOfFile<string>(kProcDirectory + kVersionFilename, 3);
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  float memTotal = findValueByKey<float>("MemTotal:", kProcDirectory+kMeminfoFilename);
  float memFree = findValueByKey<float>("MemFree:", kProcDirectory+kMeminfoFilename);
  return (memTotal-memFree)/memTotal;
  }

// Read and return the system uptime
long LinuxParser::UpTime() {
  return getValueOfFile<long>(kProcDirectory + kUptimeFilename, 1);
}

// TODO: Read and return the number of jiffies for the system
// long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
// long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
// long LinuxParser::IdleJiffies() { return 0; }

// Read and return CPU utilization
CPUStates LinuxParser::CpuUtilization() {
  string line, key, value;
  vector<int> cpuUtilization;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> key;
    while(linestream >> value) {
      cpuUtilization.push_back(stoi(value));
    }
  }
  CPUStates cpu;
  cpu.kUser_      = cpuUtilization[0];
  cpu.kNice_      = cpuUtilization[1];
  cpu.kSystem_    = cpuUtilization[2];
  cpu.kIdle_      = cpuUtilization[3];
  cpu.kIOwait_    = cpuUtilization[4];
  cpu.kIRQ_       = cpuUtilization[5];
  cpu.kSoftIRQ_   = cpuUtilization[6];
  cpu.kSteal_     = cpuUtilization[7];
  cpu.kGuest_     = cpuUtilization[8];
  cpu.kGuestNice_ = cpuUtilization[9];
  return cpu;
}

// Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  return findValueByKey<int>("processes", kProcDirectory + kStatFilename);
}

// Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  return findValueByKey<int>("procs_running", kProcDirectory + kStatFilename);
}

// Read and return the command associated with a process
string LinuxParser::Command(int pid) { 
  return getValueOfFile<string>(kProcDirectory + to_string(pid) + kCmdlineFilename);
}

// Read and return the memory used by a process
int LinuxParser::Ram(int pid) {
  // Here I used VmRSS instead of VmSize because VmSize is the sum of all the virtual memory.
  // Whereas when you use VmRSS then it gives the exact physical memory being used as a part of Physical RAM  
  int ram = findValueByKey<int>("VmRSS:", kProcDirectory + to_string(pid) + kStatusFilename);
  return ram/1024;
}

// Read and return the user ID associated with a process
string LinuxParser::Uid(int pid) { 
  return findValueByKey<string>("Uid:", kProcDirectory + to_string(pid) + kStatusFilename);
}

// Read and return the user associated with a process
string LinuxParser::User(int pid) {
  string line;
  string key;
  string value1, value2;
  std::ifstream filestream(kPasswordPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value1 >> value2) {
        if (value2 == Uid(pid)) 
          return key;
      }
    }
  }
  return key;
}

// TODO: Read and return the uptime of a process
long LinuxParser::UpTime(int pid) {
  string value;
  string line;
  long upTime = 0;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open()) {
      std::getline(stream, line);
      std::istringstream linestream(line);
      for (size_t i = 0; i < 22; i++) linestream >> value;
      upTime = UpTime() - std::stol(value)/sysconf(_SC_CLK_TCK);
  }
  return upTime; 
}
