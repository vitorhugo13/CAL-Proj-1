#include <iostream>
#include <vector>
#include "Day.h"
#include "Agenda.h"



int menuInput(int nOptions){
	int menu;
	std::cin >> menu;
	if (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Only integral numbers." << std::endl;
		return -2;
	}

	if (menu > nOptions || menu < -1){
		std::cout << "Option not valid! Try again." << std::endl;
		return -2;
	}
	return menu;
}

Day seeAgenda(){
	std::string day;
	std::cout << "In which day? (dd-mm-yyyy)"<< std::endl;
	std::cin >> day;
	Day day1(day);
	return day1;
}

int main(void) {
	
	Agenda agenda;
	agenda.loadActivities();
	int menu = -2;
	while(menu != 4){

		while(menu == -2){

			std::cout << "----- TripMate ----" << std::endl<< std::endl;
			std::cout << "0 - See Agenda" << std::endl;
			std::cout << "1 - Add activity" << std::endl;
			std::cout << "2 - Remove activity" << std:: endl;
			std::cout << "3 - See paths" << std::endl;
			std::cout << "4 - Exit " << std::endl;

			std::cout << "Option: ";
			menu = menuInput(4);
			
			
		

			if(menu == -1)
				std::cout << "Menu does not exist" << std::endl;

			switch (menu){
					case 0:{
						agenda.show(seeAgenda());
						menu = -2;
						break;
						}
						
					case 1:{
						if(agenda.addActivity()){
							std::cout<< "Activity added with success!"<< std::endl;
							agenda.saveActivities();
						}
						else{
							std::cout<< "Activity can not be added!"<< std::endl;
						}			
						menu = -2;
						break;
					}

					case 2:{
						std::string name, date;
						std::cout << "Activity's name ?" << std::endl;
						std::cin >> name;
						std::cout << "In which day? " << std::endl;
						std::cin >> date;
						Day day(date);
						if(agenda.removeActivity(name, date)){
							std::cout << "Activity removed with success! " << std::endl;
							agenda.saveActivities();
						}
						else
							std::cout << "Activity can not be removed!" << std::endl;
						menu = -2;
						break;
					}

					case 3:{
						agenda.show(seeAgenda());
						std::cout << "From which activity we want to see the path to the next activity ? " << std::endl;
						menu = -2;
						break;
					}

					case 4:
						return 0;
						
					default:
						return 0;
				}
		}
	}

    return 0;
}
