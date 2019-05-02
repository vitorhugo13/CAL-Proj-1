#ifndef TIME_H
#define TIME_H


#include <string>


#define TIME_LIMIT std::numeric_limits<unsigned short int>::max()


/**
 * @brief Class that handles time in this project.
 *  For example 06:35 is stored has 635 to make computing easier
 * 
 */
class Time {
    
private:

    unsigned short int time;

public:

    Time(std::string time) {
        //String tem de ser sempre passada com quatro digitos, ex 00:00 21:30 ...
        time.erase(2, 1);
        this->time = stoi(time, nullptr, 10);
    }

    Time(unsigned short int time) {
        //Quando se inicializa o objeto com recurso a um inteiro, o numero nao pode comecar com 0, ex 06:30 -> 0630   00:00 -> 0   22:30 -> 2230
        this->time = time;
    }

    unsigned short int getTime() const {
        return this->time;
    }

    Time operator+(Time const &obj) {
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
    
    Time operator-(Time const &obj) {
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

    Time operator+=(Time const &obj) {
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

    Time operator-=(Time const &obj) {
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

    void operator=(Time const &obj) {
        this->time = obj.time;
    }

    bool operator==(Time const &obj) {
        return this->time == obj.time;
    }

    bool operator<(Time const &obj) {
        return this->time < obj.time;
    }

    bool operator<=(Time const &obj) {
        return this->time <= obj.time;
    }

    bool operator>(Time const &obj) {
        return this->time > obj.time;
    }

    bool operator>=(Time const &obj) {
        return this->time >= obj.time;
    }
};


#endif