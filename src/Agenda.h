#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>


#include "Time.h"
#include "Day.h"
#include "Activity.h"


class Agenda {

private:

    std::vector<Activity> activities;

public:

    Agenda() {}
    bool addActivity();
    bool addActivity(Activity activity);
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
     *  @brief removes an activity
     *
     * @param name activity's name
     * @param day activity's day
     *
     * @return true if removed with success
     * @return false if not removed with success
     */
    bool removeActivity(std::string name, Day day);

    bool show(Day day);

    std::vector<Activity> activitiesOfTheDay(Day day) const;

    void loadActivities();

    void saveActivities() const;

    std::vector<Coordinates> getCoords(Day day) const;

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

    void show(std::vector<bool> onTime, Day day ) const;
};

#endif
