
#include <iostream>
#include <vector>
#include "Day.h"
#include "Agenda.h"

using namespace std;

size_t find(std::vector<int> *timetable, int startTime) {
        size_t mid, left = 0;
        size_t right = (*timetable).size();
        size_t size = right;
        
        while (left <= right) {
            mid = left + (right - left)/2;
            if (startTime > (*timetable)[mid]) {
                left = mid + 1;
            }
            else if (startTime < (*timetable)[mid]) {                                        
                right = mid;
            }
            
            if (left == size) {
                break;
            }
            else if (left == mid && mid == right) {
                return mid;
            }                                                                                                               
        }

        return 0;
    }

int menuInput(int nOptions){
	int menu;
	cin >> menu;
	if (cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only integral numbers." << endl;
		return -2;
	}

	if (menu > nOptions || menu < -1){
		cout << "Option not valid! Try again." << endl;
		return -2;
	}
	return menu;
}

int main(void) {
	std::vector<int> test = {625, 645, 700, 715, 730, 742};
    std::cout << (*&test[3]) << std::endl;

	Agenda agenda;

	int menu = -2;
	while(menu != 4){
		while(menu == -2){
			cout << "----- TripMate ----" << std::endl;
			cout << "0 - See Agenda" << std::endl;
			cout << "1 - Add activity" << std::endl;
			cout << "2 - See paths" << std::endl;
			cout << "3 - Remove Activity" << std:: endl;
			cout << "4 - Leave " << std::endl;

			menu = menuInput(4);
			if(menu == -1)
				cout << "Menu doesn't exist" << endl;
			switch (menu){
					case 0:{
						string day;
						cout << "In which day?" << endl;
						cin >> day;
						Day day1(day);
						agenda.show(day1);
						menu = -2;
						break;
						}
					case 1:{
						agenda.addActivity();
						menu = -2;
						break;
					}
					case 2:
						menu = -2;
						break;
					case 3:
						menu = -2;
						break;
					case 4:
						return 0;
					default:
						return 0;
				}
		}
	}

    return 0;
}
