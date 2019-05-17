#include "Agenda.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

bool Agenda::addActivity(){
	std::string name, info, Sday, startTime, endTime;
	std::cout << "What is the activity name ? "<< std::endl;
	std::cin >> name;
	std::cout << "What is the activity info ? "<< std::endl;
	std::cin >> info;
	std::cout << "What is the activity day (day-month-year) ? "<< std::endl;
	std::cin >> Sday;
	std::cout << "What is the activity starting time (hh:mm) ? "<< std::endl;
	std::cin >> startTime;
	std::cout << "What is the activity ending time (hh:mm)  ? "<< std::endl;
	std::cin >> endTime;
	Day day(Sday);
	Coordinates coordinates( 0 ,2);
	Activity activity(name, info, coordinates, Sday, startTime, endTime);
	return(addActivity(activity));
}

bool Agenda::addActivity(Activity activity)
{
	if(isOverlap(activity))
		return false;
    activities.push_back(activity);
    return true;
}

bool Agenda::isOverlap(Activity activity)
{
    for (Activity activity1 : activities)
    {
        if (activity1.getDay() == activity.getDay()){
        	/* se activity comeca antes de activity1, mas nao acaba a tempo */
        	if(activity1.getStartTime() > activity.getEndTime() && activity1.getEndTime() < activity.getEndTime())
            	return true;
        	/* se activity1 come�a antes de activity, mas nao acaba a tempo */
        	if(activity.getStartTime() > activity1.getEndTime() && activity.getEndTime() < activity1.getEndTime())
        		return true;
        }

    }
    return false;
}



//return true if remove with success, false otherwise.
bool Agenda::removeActivity(std::string name, Day day){
	bool in, duplicate;
	Time time("01:00");
	for(std::vector<Activity>::iterator it= activities.begin(); it !=activities.end(); it++){
			if(name == it->getName() && day == it->getDay()){
				if(!in){
					in = true;
				}
				else{
					duplicate = true;
				}
			}
		}
	if(duplicate){
		show(day);
		std::string sTime;
		std::cout << std::endl << "What is the start hour of the activity?" << std::endl;
		std::cin >> sTime;
		time.setTime(sTime);
	}

	for(std::vector<Activity>::iterator it= activities.begin(); it !=activities.end(); it++){
		if(duplicate){
			if(name == it->getName() && day == it->getDay() && time == it->getStartTime()){
				activities.erase(it);
				return true;
			}
		}
		else{
			if(name == it->getName() && day == it->getDay()){
				activities.erase(it);
				return true;
			}
		}


	}
	return false;

}


std::vector<Activity> Agenda::ActivitiesOfTheDay(Day day){
	std::vector<Activity> activitiesOfDay;
	for (Activity activity : activities){
		if(activity.getDay() == day){
			activitiesOfDay.push_back(activity);
		}
	}
	sort(activitiesOfDay.begin(), activitiesOfDay.end());
	return activitiesOfDay;
}

bool Agenda::show(Day day){
	std::vector<Activity> activitiesOfDay = ActivitiesOfTheDay(day);
	if(activitiesOfDay.size() == 0){
		std::cout << "There's no activities in this day" << std::endl << std::endl;
		return false;
	}
	std::cout << "Activities of the Day " << std::setw(10);
	std::cout << day << std::endl << std::endl;
	std::cout << "Start Time " << std::setw(10) << "Name " << std::setw(15) << "End Time" << std::setw(10) << "Info"<< std::endl;
	for (Activity activity : activitiesOfDay){
		std::cout << activity.getStartTime() << std::setw(16) << activity.getName() << std::setw(11) << activity.getEndTime() << std::setw(13) << activity.getInfo()<< std::endl;
	}
	std::cout << std::endl;
	return true;
}

