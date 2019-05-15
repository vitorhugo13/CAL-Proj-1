#include "Activity.h"
#include <string>
#include "Coordinates.h"
#include "Day.h"
#include "Time.h"

Activity::Activity(std::string info, Coordinates coord, Day day, Time startTime, Time endTime) :
	info(info), coords(coord), day(day), startTime(startTime), endTime(endTime)
{ }

std::string Activity::getInfo()
{
    return info;
}

Coordinates Activity::getCoords()
{
    return coords;
}

Day Activity::getDay()
{
    return day;
}

Time Activity::getStartTime()
{
    return startTime;
}

Time Activity::getEndTime()
{
    return endTime;
}
