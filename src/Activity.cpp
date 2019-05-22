#include <string>


#include "Activity.h"
#include "Day.h"
#include "Time.h"


class InvalidTime { };


Activity::Activity(std::string name,std::string info, Coordinates coord, Day day, Time startTime, Time endTime) :
	name(name), info(info), coords(coord), day(day), startTime(startTime), endTime(endTime) {
	if(startTime > endTime || startTime == endTime)
		throw InvalidTime();
}

std::string Activity::getName() {
    return name;
}

std::string Activity::getInfo() {
    return info;
}

Coordinates Activity::getCoords() {
    return coords;
}

Day Activity::getDay() {
    return day;
}

Time Activity::getStartTime() {
    return startTime;
}

Time Activity::getEndTime() {
    return endTime;
}

bool Activity::operator==(Activity &A1) {
	return( this->name == A1.getName() && this->name == A1.getName() );
}

bool Activity::operator>(Activity &A1) {
	return( this->startTime > A1.getStartTime() );
}

bool Activity::operator<(Activity &A1) {
	return( this->startTime < A1.getStartTime() );
}
