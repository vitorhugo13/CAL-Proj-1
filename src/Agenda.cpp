#include "Agenda.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;
bool Agenda::addActivity(Activity *activity)
{
	if(isOverlap(activity))
		return false;
    activities.push_back(activity);
    return true;
}

bool Agenda::isOverlap(Activity *activity)
{
    for (Activity *activity1 : activities)
    {
        if (activity1->getDay() == activity->getDay()){
        	/* se activity começa antes de activity1, mas não acaba a tempo */
        	if(activity1->getStartTime() > activity->getEndTime() && activity1->getEndTime() < activity->getEndTime())
            	return true;
        	/* se activity1 começa antes de activity, mas não acaba a tempo */
        	if(activity->getStartTime() > activity1->getEndTime() && activity->getEndTime() < activity1->getEndTime())
        		return true;
        }

    }
    return false;
}

bool Agenda::removeAtivity(Activity * activity){
	return false;

}

std::vector<Activity *> Agenda::ActivitiesOfTheDay(Day day){
	std::vector<Activity *> activitiesOfDay;
	for (Activity *activity : activities){
		if(activity->getDay() == day){
			activitiesOfDay.push_back(activity);
		}
	}
	sort(activitiesOfDay.begin(), activitiesOfDay.end());
	return activitiesOfDay;
}

bool Agenda::show(Day day){
	std::vector<Activity *> activitiesOfDay = ActivitiesOfTheDay(day);
	if(activitiesOfDay.size() == 0){
		cout << "There's no activities in this day" << std::endl;
		return false;
	}
	cout << "Activities of the Day " << setw(10);
	cout << day << endl;
	cout << "Start Time " << setw(10) << "Name " << setw(15) << "End Time" << endl;
	for (Activity *activity : activitiesOfDay){
		cout << activity->getStartTime() << setw(16) << activity->getName() << setw(10) << activity->getEndTime() << endl;
	}
	return true;
}

