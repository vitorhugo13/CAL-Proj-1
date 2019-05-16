
#include <iostream>
#include <vector>
#include "Day.h"
#include "Agenda.h"

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


int main(void) {
	std::vector<int> test = {625, 645, 700, 715, 730, 742};
    std::cout << (*&test[3]) << std::endl;


	Agenda agenda;

    std::cout << "TripMate" << std::endl;
    std::cout << "See Agenda" << std::endl;
    std::cout << "Add activity" << std::endl;
    std::cout << "See paths" << std::endl;

   std::string name, info, Sday, startTime, endTime;
   std::cout << "What큦 the activity name ? "<< std::endl;
    std::cin >> name;
    std::cout << "What큦 the activity info ? "<< std::endl;
    std::cin >> info;
    std::cout << "What큦 the activity day (day-month-year) ? "<< std::endl;
    std::cin >> Sday;
    std::cout << "What큦 the activity starting time (hous:minutes) ? "<< std::endl;
    std::cin >> startTime;
    std::cout << "What큦 the activity ending time (hous:minutes)  ? "<< std::endl;
    std::cin >> endTime;
    Day day(Sday);
    Coordinates coordinates( 0 ,2);
    Activity activity(name, "", coordinates, Sday,startTime, endTime );
    agenda.addActivity(&activity);

    agenda.show(Sday);





    std::cout << "The end "<< std::endl;
    return 0;
}
