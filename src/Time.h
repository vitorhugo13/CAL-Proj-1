#ifndef TIME_H
#define TIME_H

#include <string>
#include <limits>

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

    Time();

    Time(double time);

    /* String tem de ser sempre passada com quatro digitos, ex 00:00 21:30 ... */
    Time(std::string time);

    /* Quando se inicializa o objeto com recurso a um inteiro, o numero nao pode comecar com 0, ex 06:30 -> 0630   00:00 -> 0   22:30 -> 2230 */
    Time(unsigned short int time);

    unsigned short int getTime() const;

    void setTime(std::string time);

    Time operator+(Time const &obj) const;

    Time operator-(Time const &obj) const;

    Time operator+=(Time const &obj);

    Time operator-=(Time const &obj);
    
    bool operator==(Time const &obj) const;

    bool operator<(Time const &obj) const;

    bool operator<=(Time const &obj) const;

    bool operator>(Time const &obj) const;

    bool operator>=(Time const &obj) const;

    std::string getTimeString() const;

    friend std::ostream& operator<< (std::ostream &os, const Time &t);
};


#endif
