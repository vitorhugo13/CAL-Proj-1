#ifndef AGENDA_H
#define AGENDA_H

#include "Coordinates.h"
#include "Time.h"
#include "Day.h"
#include "Activity.h"

#include <vector>
#include <string>

class Agenda
{

private:
    std::vector<Activity> activities;

public:
    Agenda() {}
    bool addActivity();
    bool addActivity(Activity activity);
    bool isOverlap(Activity activity);
    bool removeActivity(std::string name, Day day);
    bool show(Day day);
    std::vector<Activity> ActivitiesOfTheDay(Day day);
};

#endif
