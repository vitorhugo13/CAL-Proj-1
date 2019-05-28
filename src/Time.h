#ifndef TIME_H
#define TIME_H

#include <string>
#include <limits>

#define TIME_LIMIT std::numeric_limits<double>::max()

/**
 * @brief Class that handles time in this project
 * 
 */
class Time {
    
private:

    /**
     * @brief number of hours
     * 
     */
    double time;

public:
    /**
     * @brief Construct a new Time object
     * 
     */
    Time();
     
    /**
     * @brief Construct a new Time object
     * 
     * @param time number of hours
     */
    Time(double time);

    /**
     * @brief Construct a new Time object
     * 
     * @param time string that correspondes a time
     */
    Time(std::string time);

    /**
     * @brief Get the Time object
     * 
     * @return double returns time
     */
    double getTime() const;

    /**
     * @brief Set the Time object
     * 
     * @param time time to be set
     */
    void setTime(std::string time);

    /**
     * @brief Set the Time object
     * 
     * @param time time to be set
     */
    void setTime(double time);

    /**
     * @brief overload + operator for the time class
     * 
     * @param obj 
     * @return Time time after operation
     */
    Time operator+(Time const &obj) const;

    /**
     * @brief overload - operator for the time class
     * 
     * @param obj 
     * @return Time time after operation
     */
    Time operator-(Time const &obj) const;

    /**
     * @brief overload += operator for the time class
     * 
     * @param obj 
     * @return Time time after operation
     */
    Time operator+=(Time const &obj);

    /**
     * @brief overload -= operator for the time class
     * 
     * @param obj 
     * @return Time time after operation
     */
    Time operator-=(Time const &obj);
    
    /**
     * @brief overload == operator for the time class
     * 
     * @param obj time that will be compared against
     * @return true objects are equal
     * @return false objects are not equal
     */
    bool operator==(Time const &obj) const;

    /**
     * @brief overload < operator for the time class
     * 
     * @param obj time that will be compared against 
     * @return true this object is previous to obj
     * @return false this object is not previous to obj
     */
    bool operator<(Time const &obj) const;

    /**
     * @brief overload <= operator for the time class
     * 
     * @param obj time that will be compared against 
     * @return true this object is previous or equal to obj
     * @return false this object is not previous to obj
     */
    bool operator<=(Time const &obj) const;

    /**
     * @brief overload > operator for the time class
     * 
     * @param obj time that will be compared against
     * @return true this object is posterior to obj
     * @return false this object is not posterior to obj 
     */
    bool operator>(Time const &obj) const;

    /**
     * @brief overload >= operator for the time class
     * 
     * @param obj time that will be compared against
     * @return true this object is posterior or equal to obj
     * @return false this object is not posterior or equal to obj
     */
    bool operator>=(Time const &obj) const;

    /**
     * @brief Get the Time String object
     * 
     * @return std::string time string
     */
    std::string getTimeString() const;

    /**
	 * @brief Outstream operator overload for class Time
	 * 
	 * @param os Output stream
	 * @param t time wanted
	 * @return ostream& Output stream
	 */
    friend std::ostream& operator<< (std::ostream &os, const Time &t);
};


#endif
