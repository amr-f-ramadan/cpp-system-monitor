#include <string>
#include <vector>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

string Format::ElapsedTime(long time) { 
    string hours = to_string(time/3600);
    if (hours.length() < 2) hours = "0" + hours;
    time %= 3600;
    string minutes = to_string(time/60);
    if (minutes.length() < 2) minutes = "0" + minutes;
    string seconds = to_string(time%60);
    if (seconds.length() < 2) seconds = "0" + seconds;    
    return hours + ":" + minutes + ":" + seconds; 
    }

