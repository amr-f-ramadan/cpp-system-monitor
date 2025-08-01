#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid){}

// Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() { 
    string value;
    string line;
    float cpu_usage = 0.0;
    std::ifstream stream(LinuxParser::kProcDirectory + to_string(pid_) + LinuxParser::kStatFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        int utime, stime, cutime, cstime, starttime;
        int uptime = LinuxParser::UpTime();
        float Hertz = sysconf(_SC_CLK_TCK);
        for (size_t i = 1; i <= 22; i++)
        {
            linestream >> value;
            switch (i)
            {
            case 14: utime     = std::stoi(value); break;
            case 15: stime     = std::stoi(value); break;
            case 16: cutime    = std::stoi(value); break;
            case 17: cstime    = std::stoi(value); break;
            case 22: starttime = std::stoi(value); break;
            default: break;
            }                
        }
        float total_time = utime + stime + cutime + cstime;
        float seconds = uptime - (starttime / Hertz);
        cpu_usage = (total_time / Hertz) / seconds;
    }
    return cpu_usage; 
}

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Return this process's memory utilization
int Process::Ram() { return LinuxParser::Ram(pid_); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// Overload the "less than" comparison operator for Process objects
// The operator '<' is overloaded to compare processes based on cpu utilization
bool Process::operator<(Process & a) { 
    return a.CpuUtilization() < CpuUtilization(); }