#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include "Coordinates.h"
#include "Day.h"
#include "Time.h"

/**
 * @brief This has all Activity related methods
 * 
 */
class Activity {

private:
   /**
    * @brief activity's name
    * 
    */
	std::string name;

   /**
    * @brief activity's information
    * 
    */
    std::string info;

   /**
    * @brief activity's coordinates
    * 
    */
    Coordinates coords;

   /**
    * @brief activity's day
    * 
    */
    Day day;

   /**
    * @brief activity's start time
    * 
    */
    Time startTime;

   /**
    * @brief activity's end time
    * 
    */
    Time endTime;

public:
    /**
     * @brief construct a new activity object
     * 
     * @param name activity's name
     * @param info activity's info
     * @param coord activity's coordinates
     * @param day activity's day
     * @param startTime activity's start time
     * @param endTime activity's end time
     */
    Activity(std::string name, std::string info, Coordinates coord, Day day, Time startTime, Time endTime);

    /**
     * @brief gets activity's name
     * 
     * @return activity's name
     */
    std::string getName();

    /**
     * @brief gets activity's info
     * 
     * @return activity's info
     */
    std::string getInfo();

    /**
     * @brief gets activity's coordinates
     * 
     * @return activity's coordinates
     */
    Coordinates getCoords();

    /**
     * @brief gets activity's day
     * 
     * @return activity's day
     */
    Day getDay();

    /**
     * @brief gets activity's start time
     * 
     * @return activity's start time
     */
    Time getStartTime();

    /**
     * @brief gets activity's end time
     * 
     * @return activity's end time
     */
    Time getEndTime();

    /**
     * @brief shows activities
     * 
     */
    void show();

    /**
	 * @brief Overloaded operator == for the activity class.
	 * 
	 * @param A1 activity that will be compared against
	 * @return true This activity is equal to A1
	 * @return false A1 is not equal to this Activity
	 */
    bool operator==(Activity &A1);

    /**
	 * @brief Overloaded operator < for the activity class.
	 * 
	 * @param A1 activity that will be compared against
	 * @return true This activity is smaller than A1
	 * @return false A1 is smaller than this Activity
	 */
    bool operator<(Activity &A1);

    /**
	 * @brief Overloaded operator > for the activity class.
	 * 
	 * @param A1 activity that will be compared against
	 * @return true This activity is greater than A1
	 * @return false A1 is greater than this Activity
	 */
    bool operator>(Activity &A1);

};

#endif //ACTIVITY_H
