#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include "Coordinates.h"
#include "Day.h"
#include "Time.h"

class Activity
{
private:
	std::string name;
    std::string info;
    Coordinates coords;
    Day day;
    Time startTime, endTime;

public:
    Activity(std::string name, std::string info, Coordinates coord, Day day, Time startTime, Time endTime);
    std::string getInfo();
    Coordinates getCoords();
    Day getDay();
    Time getStartTime();
    Time getEndTime();
    void show();
};

#endif //ACTIVITY_H
