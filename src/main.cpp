
#include <iostream>
#include <vector>
#include "Day.h"

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

    std::cout << "TripMate" << std::endl;
    std::cout << "See Agenda" << std::endl;
    std::cout << "Add activity" << std::endl;
    std::cout << "See paths" << std::endl;

    std::string name, Sday;
    std::cout << "What´s the activity name ? "<< std::endl;
    std::cin >> name;
    std::cout << "What´s the activity day (day-month-year) ? "<< std::endl;
    std::cin >> Sday;
    Day day(Sday);
    std::cout << "The end "<< std::endl;
    return 0;
}
