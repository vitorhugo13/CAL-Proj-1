#ifndef AGENDA_H
#define AGENDA_H


#include <vector>
#include <string>

#include "Coordinates.h"
#include "Time.h"
#include "Day.h"

class Activity;

class Agenda {

private:
    std::vector<Activity *> activities;
};

class Activity {

private:
    std::string info;
    Coordinates coords;
    Day day;
    Time startTime, endTime;

public:

};


#endif
