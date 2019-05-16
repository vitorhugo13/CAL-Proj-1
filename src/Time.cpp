#include "Time.h"

Time::Time(std::string time) {
	 time.erase(2, 1);
	 this->time = stoi(time, nullptr, 10);
 }

Time::Time(unsigned short int time) {
	this->time = time;
}

unsigned short int Time::getTime() const {
	return this->time;
}

void Time::setTime(std::string time){
	time.erase(2, 1);
	this->time = stoi(time, nullptr, 10);
}

Time Time::operator+(Time const &obj) {
        unsigned char carry = 0;
        unsigned short int thisHours, thisMinutes, objHours, objMinutes;

        thisHours = this->time / 100;
        thisMinutes = this->time % 100;

        objHours = obj.getTime() / 100;
        objMinutes = obj.getTime() % 100;

        thisMinutes += objMinutes;
        if(thisMinutes > 59) {
            carry = 1;
            thisMinutes = thisMinutes - 60;
        }

        if(carry == 1) {
            thisHours += objHours + 1;
            if(thisHours > 23)  thisHours = 0 + (thisHours - 24);
        }else {
            thisHours += objHours;
            if(thisHours > 23)  thisHours = 0 + (thisHours - 24);
        }

        unsigned short int result = thisHours * 100 + thisMinutes;

        if(result == 2400)  result = 0;

        return result;
    }

Time Time::operator-(Time const &obj) {
        unsigned char carry = 0;
        short int thisHours, thisMinutes, objHours, objMinutes;

        thisHours = this->time / 100;
        thisMinutes = this->time % 100;

        objHours = obj.getTime() / 100;
        objMinutes = obj.getTime() % 100;

        thisMinutes -= objMinutes;
        if(thisMinutes < 0) {
            carry = 1;
            thisMinutes = 60 + thisMinutes;
        }

        if(carry == 1) {
            thisHours -= objHours - 1;
            if(thisHours < 0)  thisHours = 24 + (thisHours - 24);
        }else {
            thisHours -= objHours;
            if(thisHours < 0)  thisHours = 24 + thisHours;
        }

        unsigned short int result = thisHours * 100 + thisMinutes;

        if(result == 2400)  result = 0;

        return result;
    }

    Time Time::operator+=(Time const &obj) {
        unsigned char carry = 0;
        unsigned short int thisHours, thisMinutes, objHours, objMinutes;

        thisHours = this->time / 100;
        thisMinutes = this->time % 100;

        objHours = obj.getTime() / 100;
        objMinutes = obj.getTime() % 100;

        thisMinutes += objMinutes;
        if(thisMinutes > 59) {
            carry = 1;
            thisMinutes = thisMinutes - 60;
        }

        if(carry == 1) {
            thisHours += objHours + 1;
            if(thisHours > 23)  thisHours = 0 + (thisHours - 24);
        }else {
            thisHours += objHours;
            if(thisHours > 23)  thisHours = 0 + (thisHours - 24);
        }

        unsigned short int result = thisHours * 100 + thisMinutes;

        if(result == 2400)  this->time = result = 0;

        return this->time = result;
    }

Time Time::operator-=(Time const &obj) {
        unsigned char carry = 0;
        short int thisHours, thisMinutes, objHours, objMinutes;

        thisHours = this->time / 100;
        thisMinutes = this->time % 100;

        objHours = obj.getTime() / 100;
        objMinutes = obj.getTime() % 100;

        thisMinutes -= objMinutes;
        if(thisMinutes < 0) {
            carry = 1;
            thisMinutes = 60 + thisMinutes;
        }

        if(carry == 1) {
            thisHours -= objHours - 1;
            if(thisHours < 0)  thisHours = 24 + (thisHours - 24);
        }else {
            thisHours -= objHours;
            if(thisHours < 0)  thisHours = 24 + thisHours;
        }

        unsigned short int result = thisHours * 100 + thisMinutes;

        if(result == 2400)  result = 0;

        return this->time = result;
    }

void Time::operator=(Time const &obj) {
        this->time = obj.time;
    }

bool Time::operator==(Time const &obj) {
        return this->time == obj.time;
    }

    bool Time::operator<(Time const &obj) {
        return this->time < obj.time;
    }

    bool Time::operator<=(Time const &obj) {
        return this->time <= obj.time;
    }

    bool Time::operator>(Time const &obj) {
        return this->time > obj.time;
    }

    bool Time::operator>=(Time const &obj) {
        return this->time >= obj.time;
    }

std::ostream& operator<< (std::ostream &os, const Time &t){
    	std::string hours, mins;
    	int min = t.getTime() % 100;
    	int hour = t.getTime() - min;
    	if(hour/100 <10)
    		hours = "0" + std::to_string(hour/100) + ":";
    	else
    		hours = std::to_string(hour/100) + ":";
    	if(min < 10)
    		mins = "0" + std::to_string(min);
    	else
    		mins = std::to_string(min);
    	os << hours << mins;
    	return os;
    }
