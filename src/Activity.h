#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include "Coordinates.h"
#include "Day.h"
#include "Time.h"

class Activity {
private:
    std::string info;
    Coordinates coords;
    Day day;
    Time startTime, endTime;
public:
    Activity(std::string info, Coordinates coords, Day day, Time startTime, Time endTime);
    std::string getInfo();
    Coordinates getCoords();
    Day getDay();
    Time getStartTime();
    Time getEndTime();
};


#endif //ACTIVITY_H
