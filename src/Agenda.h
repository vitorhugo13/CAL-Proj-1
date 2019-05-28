#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>


#include "Time.h"
#include "Day.h"
#include "Activity.h"


class Agenda {

private:
    /**
     * @brief vector containing activities
     * 
     */
    std::vector<Activity> activities;

public:

    /**
     * @brief Construct a new Agenda object
     * 
     */
    Agenda() {}

    /**
     * @brief adds a new activity
     * 
     * @return true added with success
     * @return false can not be added
     */
    bool addActivity();

    /**
     * @brief 
     * 
     * @param activity activity to be add
     * @return true added with success
     * @return false can not be added
     */
    bool addActivity(Activity activity);

    /**
     * @brief checks if the activity overlaps other activity
     * 
     * @param activity activity to be checked
     * @return true is overlapping
     * @return false is not overlapping
     */
    bool isOverlap(Activity activity);

    /*
     * @brief verify if the activity's duplicate
     * 
     *
     * @param name activity's name
     * @param day activity's day
     * 
     * @return true if it's duplicated
     * @return false if it isn't duplicated
     */
    bool duplicateActivities(std::string name,Day day);

    /*
     * @brief removes an activity
     *
     * @param name activity's name
     * @param day activity's day
     *
     * @return true if removed with success
     * @return false if not removed with success
     */
    bool removeActivity(std::string name, Day day);

    /**
     * @brief shows all the activity's of a certain day
     * 
     * @param day day we are looking for
     * @return true displayed with success
     * @return false there's no activities
     */
    bool show(Day day);

    /**
     * @brief 
     * 
     * @param day day we are looking to see the activities
     * @return vector<Activity> activity's in that day
     */
    std::vector<Activity> activitiesOfTheDay(Day day) const;

    /**
     * @brief load all activities from a text file
     * 
     */
    void loadActivities();

    /**
     * @brief save all activities to a txt file
     * 
     */
    void saveActivities() const;

    /**
     * @brief Gets activity's coordinates
     * 
     * @param day day we wanna see the coordinates
     * @return vector<Coordinates> returns the coordinates of all the activity's during a day
     */
    std::vector<Coordinates> getCoords(Day day) const;

    /**
     * @brief 
     * 
     * @param a activity user's leaving
     * @param b acitivity user's going
     * @param travel travel's time
     * @return true user will be on time
     * @return false user won't be on time
     */
    bool onTime(Activity a, Activity b, Time travel) const;

    /**
     * @brief Sees if we are going to be on time
     * 
     * @param travelTime vector with all the travel's time
     * @param day day to be analized
     * 
     * @return vector with boolean values saying if we are or not in time
     */
    std::vector<bool> onTime(std::vector<Time> travelTime, Day day) const;

    /**
     * @brief shows if we're going to be or not in time
     * 
     * @param onTime vector with the time information
     * @param day day we are looking for
     */
    void show(std::vector<bool> onTime, Day day ) const;
};

#endif
