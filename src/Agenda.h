#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>

#include "Coordinates.h"
#include "Time.h"
#include "Day.h"
#include "Activity.h"

class Agenda
{

private:
    std::vector<Activity *> activities;

public:
    Agenda() {}
    bool addActivity(Activity *activity);
    bool isOverlap(Activity *activity);
    bool removeAtivity(Activity * activity);
};

#endif
