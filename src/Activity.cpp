#include "Activity.h"

Activity::Activity(std::string info, Coordinates coords, Day day, Time startTime, Time endTime){
    this.info = info;
    this.coords = coords;
    this.day = day;
    this.startTime = startTime;
    this.endTime = endTime;
}

std::string Activity::getInfo(){
   return info;
}

Coordinates Activity::getCoords(){
   return coords;
}

 Day Activity::getDay(){
        return day;
    }
    Time Activity::getStartTime(){
        return startTime;
    }
    Time Activity::getEndTime(){
        return endTime;
    }

