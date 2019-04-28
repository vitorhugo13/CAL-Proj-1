#ifndef TIME_H
#define TIME_H

#include <string>


#define TIME_LIMIT std::numeric_limits<unsigned short int>::max()



/**
 * @brief Class that handles time in this project.
 *  For example 06:35 is stored has 0635 to make computing easier
 * 
 */
class Time {
    
private:
    unsigned short int time;

public:
    Time(std::string time);
    Time(unsigned short int time) {
        this.time = time;
    }

    Time operator+(Time const &obj);
    Time operator-(Time const &obj);
    Time operator-=(Time const &obj);
    Time operator+=(Time const &obj);
    Time operator=(Time const &obj) {
        return obj;
    }
};


#endif