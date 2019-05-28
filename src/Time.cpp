#include <cmath>
#include <algorithm>

#include "Time.h"


Time::Time() {
    time = TIME_LIMIT;
}
    
Time::Time(double time) {
    this->time = time;
}

Time::Time(std::string time) {

    std::string delimiter = ":";

    size_t pos = time.find(delimiter);
    this->time = std::stoi(time.substr(0, pos));  //hours
    time.erase(0, pos + delimiter.length());

    pos = time.find(delimiter);
    this->time += std::stoi(time.substr(0, pos)) / 60.0;
    time.erase(0, pos + delimiter.length());

    this->time += std::stoi(time) / 3600;
}

double Time::getTime() const {
	return this->time;
}

void Time::setTime(std::string time){
    
    std::string delimiter = ":";

    size_t pos = time.find(delimiter);
    this->time = std::stoi(time.substr(0, pos));  //hours
    time.erase(0, pos + delimiter.length());

    pos = time.find(delimiter);
    this->time += std::stoi(time.substr(0, pos)) / 60.0;
    time.erase(0, pos + delimiter.length());

    this->time += std::stoi(time) / 3600;
}

Time Time::operator+(Time const &obj) const {
    return this->time + obj.time;
}

Time Time::operator-(Time const &obj) const {
    return (this->time - obj.time >= 0) ? this->time - obj.time : 0;
}

Time Time::operator+=(Time const &obj) {
    return this->time += obj.time;
}

Time Time::operator-=(Time const &obj) {
    return this->time -= obj.time;
}

bool Time::operator==(Time const &obj) const {
    return this->time == obj.time;
}

bool Time::operator<(Time const &obj) const {
    return this->time < obj.time;
}

bool Time::operator<=(Time const &obj) const {
    return this->time <= obj.time;
}

bool Time::operator>(Time const &obj) const {
    return this->time > obj.time;
}

bool Time::operator>=(Time const &obj) const {
    return this->time >= obj.time;
}


std::string Time::getTimeString() const {
    int hours = floor(time);
    int mins = floor(time - hours * 60);
    int secs = floor(time * 3600 - hours * 3600 - mins * 60);

    std::string result = std::to_string(hours) + ":" + std::to_string(mins) + ":" + std::to_string(secs);
    return result;
}


std::ostream& operator<< (std::ostream &os, const Time &t) {
    os << t.getTimeString();
    return os;
}