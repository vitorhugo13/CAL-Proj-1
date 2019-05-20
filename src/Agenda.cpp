#include "Agenda.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>


bool Agenda::addActivity(){

	std::string name, info, date, startTime, endTime;
	std::cout << "Activity's name ? "<< std::endl;
	std::cin >> name;

	std::cout << "Activity's info ? "<< std::endl;
	std::cin.ignore();
	std::getline(std::cin, info);

	std::cout << "Activity's date (day-month-year) ? "<< std::endl;
	std::cin >> date;

	std::cout << "Activity's starting time (hh:mm) ? "<< std::endl;
	std::cin >> startTime;
	
	std::cout << "Activity's ending time (hh:mm)  ? "<< std::endl;
	std::cin >> endTime;

	Day day(date);
	Coordinates coordinates( 0 ,2);
	Activity activity(name, info, coordinates, date, startTime, endTime);

	return(addActivity(activity));
}


bool Agenda::addActivity(Activity activity)
{
	if(isOverlap(activity)){
		return false;
	}

    activities.push_back(activity);
    return true;
}


bool Agenda::isOverlap(Activity activity)
{
    for (Activity activity1 : activities)
    {

        if (activity1.getDay() == activity.getDay()){

        	if(!((activity1.getStartTime() >= activity.getEndTime() ) || (activity1.getEndTime() <= activity.getStartTime()))){
				return true;
				//means the dates overlap
			}

        }

    }

    return false; 
	//we do not have overlap on dates
}

bool Agenda::duplicateActivities(std::string name,Day day){
	bool in, duplicate;

	for(std::vector<Activity>::iterator it= activities.begin(); it !=activities.end(); it++){
			if((name == it->getName()) && (day == it->getDay())){
				if(!in){
					in = true;
				}
				else{
					duplicate = true;
				}
			}
	}
	return duplicate;
}


bool Agenda::removeActivity(std::string name, Day day){

	int duplicate = duplicateActivities(name, day);
	Time time("01:00"); //can be init4ialized with any value

	if(duplicate){
		show(day);
		std::string sTime;
		std::cout << std::endl << "Activity start hour?" << std::endl;
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
		std::cout << "There's no activities in this day!" << std::endl << std::endl;
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
void Agenda::loadActivities(){

	std::ifstream mfile;

	mfile.open ("agenda.txt");

	while (!mfile.eof()) {
		long int x, y;
		std::string name, info, date, Stime, Ftime;
		mfile >> name;
		if (name == "")
			break;
		mfile.ignore(1);
		mfile >> x;
		mfile.ignore(1);
		mfile >> y;
		mfile.ignore(1);
		mfile >> date;
		mfile.ignore(1);
		mfile >> Stime;
		mfile.ignore(1);
		mfile >> Ftime;
		mfile.ignore(1);
		std::getline(mfile, info);
		Coordinates c(x, y);
		Day day(date);
		Time startTime(Stime);
		Time endTime(Ftime);
		Activity a(name, info, c, day, startTime, endTime);
		activities.push_back(a);
	}
	mfile.close();


}

void Agenda::saveActivities()const{

	std::ofstream mfile;

	mfile.open ("agenda.txt");

	for (Activity activity : activities){
		mfile << activity.getName() << " " << activity.getCoords().getX() << " " << activity.getCoords().getY() << " " <<
				activity.getDay() << " " << activity.getStartTime() << " " << activity.getEndTime() << " " << activity.getInfo() << std::endl;
	}

	mfile.close();

}
