#include "processor.h"
#include <vector>
#include <unistd.h>

using std::vector;
using namespace LinuxParser;
// Return the aggregate CPU utilization
double Processor::Utilization() {
    CPUStates cpu = LinuxParser::CpuUtilization();
    unsigned int prev_Idle, prev_NonIdle, prev_Total;
    prev_Idle = cpu.kIdle_ + cpu.kIOwait_;
    prev_NonIdle = cpu.kUser_ + cpu.kNice_ + cpu.kSystem_+ cpu.kIRQ_ 
    + cpu.kSoftIRQ_ + cpu.kSteal_ + cpu.kGuest_ + cpu.kGuestNice_;
    prev_Total = prev_Idle + prev_NonIdle;

    usleep(500000);//sleeps for 500 milliseconds

    cpu = LinuxParser::CpuUtilization();
    unsigned int Idle, NonIdle, Total;
    Idle = cpu.kIdle_ + cpu.kIOwait_;
    NonIdle = cpu.kUser_ + cpu.kNice_ + cpu.kSystem_+ cpu.kIRQ_ 
    + cpu.kSoftIRQ_ + cpu.kSteal_ + cpu.kGuest_ + cpu.kGuestNice_;
    Total = Idle + NonIdle;

    // differentiate: actual value minus the previous one
    double totald = Total - prev_Total;
    double idled = Idle - prev_Idle;

    return (totald - idled)/(totald);
}