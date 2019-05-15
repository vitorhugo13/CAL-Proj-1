#include "Agenda.h"

bool Agenda::addActivity(Activity *activity)
{
    activities.push_back(activity);
    return true;
}

bool Agenda::isOverlap(Activity *activity)
{
    for (Activity *activity1 : activities)
    {
        if (activity1->getDay() == activity->getDay())
            return true;
    }
    return false;
}
