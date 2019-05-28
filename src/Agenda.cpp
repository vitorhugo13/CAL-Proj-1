#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>


#include "Agenda.h"

bool Agenda::addActivity(){

	std::string name, info, date, startTime, endTime;
	double x, y;
	std::cout << "Activity's name ? "<< std::endl;
	std::cin.ignore();
	getline(std::cin,name);

	std::cout << "Activity's info ? "<< std::endl;
	//std::cin.ignore();
	std::getline(std::cin, info);

	std::cout << "Activity's date (day-month-year) ? "<< std::endl;
	std::cin >> date;

	std::cout << "Activity's starting time (hh:mm) ? "<< std::endl;
	std::cin >> startTime;
	
	std::cout << "Activity's ending time (hh:mm)  ? "<< std::endl;
	std::cin >> endTime;

	std::cout << "What's the activity x coordinate ? " << std::endl;
	std::cin >> x;

	std::cout << "What's the activity x coordinate ? " << std::endl;
	std::cin >> y;

	Day day(date);
	Coordinates coordinates(x ,y);
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
		std::cout << std::endl << "Activity starting hour?" << std::endl;
		std::cin >> sTime;
		time.setTime(sTime);
	}

	for(std::vector<Activity>::iterator it= activities.begin(); it !=activities.end(); it++){
		if(duplicate){
			if(name == it->getName() && day == it->getDay() && time == it->getStartTime()){
				activities.erase(it);
				saveActivities();
				return true;
			}
		}
		else{
			if(name == it->getName() && day == it->getDay()){
				activities.erase(it);
				saveActivities();
				return true;
			}
		}
	
	}

	return false;

}

std::vector<Activity> Agenda::activitiesOfTheDay(Day day) const {
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
	std::vector<Activity> activitiesOfDay = activitiesOfTheDay(day);

	if(activitiesOfDay.size() == 0){
		std::cout << "There's no activities in this day!" << std::endl << std::endl;
		return false;
	}

	std:: cout << std::endl;
	std::cout << "Activities of the Day " << std::setw(10);
	std::cout << day << std::endl;
	std::cout << "Start Time " << std::setw(10) << "Name " << std::setw(15) << "End Time" << std::setw(10) << "Info"<< std::endl;
	for (Activity activity : activitiesOfDay){
		std::cout << activity.getStartTime() << std::setw(18) << activity.getName() << std::setw(9) << activity.getEndTime() << std::setw(18) << activity.getInfo()<< std::endl;
	}
	std::cout << std::endl;
	return true;
}


//Solução encontrada: ao invés de colocarmos toda a informação de uma atividade numa só linha, será distribuida por 2
//a primeira com o nome da atividade, o que vai fazer com que se consiga extrair facilmente atividades com nomes compostos por 2 ou mais palavras
//a segunda com a restante informaçao conforme estava anteriormente
//exemplo
//go to the gym     <- line 1
//0 2 22/05/2019 11:00 12:30 with friends <- line 2

void Agenda::loadActivities(){

	std::ifstream mfile;

	int count_lines=1;

	mfile.open ("data/agenda.txt");

	long int x, y;
	std::string name, info, date, Stime, Ftime;

	while (!mfile.eof()) {

	if(count_lines == 1){
		std::getline(mfile,name);
		if(name == "")
			break;
		count_lines++;
	}
	

	if(count_lines == 2){	
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

		//create objects with the extract information from agenda.txt
		Coordinates c(x, y);
		Day day(date);
		Time startTime(Stime);
		Time endTime(Ftime);
	
		//create an activity with the previous objects
		Activity a(name, info, c, day, startTime, endTime);
		activities.push_back(a);

		count_lines=1;
	}

	}

	mfile.close();

}

void Agenda::saveActivities()const{

	std::ofstream mfile;

	mfile.open ("data/agenda.txt");

	for (Activity activity : activities){
		mfile << activity.getName() <<std::endl;
		mfile<< activity.getCoords().getX() << " " << activity.getCoords().getY() << " " <<activity.getDay() << " " << activity.getStartTime() << " " << activity.getEndTime() << " " << activity.getInfo() << std::endl;
	}

	mfile.close();

}
std::vector<Coordinates> Agenda::getCoords(Day day) const {
	std::vector<Activity > act = activitiesOfTheDay(day); //activities are sorted by time
	std::vector<Coordinates> coor;
	for(Activity activity : act){
		coor.push_back(activity.getCoords());
	}
	return coor;
}

bool Agenda::onTime(Activity a, Activity b, Time travel) const{
	return (a.getEndTime () - b.getStartTime() > travel );
}

std::vector<bool> Agenda::onTime(std::vector<Time> travelTime, Day day) const{
	std::vector<bool> notLate;
	std::vector<Activity> activities = activitiesOfTheDay(day);
	for(size_t i = 0; i < activities.size()-1; i++){
		notLate.push_back(onTime(activities.at(i), activities.at(i+1), travelTime.at(i)));
	}
	return notLate;
}

void Agenda::show(std::vector<bool> onTime, Day day ) const{
	
	std::vector<Activity> activities = activitiesOfTheDay(day);

	if(activities.size() < 2){ //if there aren't activities or only one
		std::cout << "There's not enought activities in this day!" << std::endl << std::endl;
		return;
	}
	if(activities.size() > onTime.size() + 1){
		std::cout << "An error occurred " << std::endl;
		return;
	}
	std:: cout << std::endl;
	std::cout << "On this day: " << std::setw(10);
	std::cout << day << std::endl;
	
	for(size_t i = 1; i < activities.size(); i++){
		std::cout << activities.at(i).getName() << std::setw(10);
		if(onTime.at(i-1)){
			std::cout << "Going to be on time"<< std::endl;
		} else{
			std::cout << "Going to be on late "<< std::endl;
		}
	}
}



