#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <map>
#include <string>

struct timetable {
    std::vector<unsigned int> forward;
    std::vector<unsigned int> backwards;
}


class Vehicle {

private:
    static unsigned int id;
    std::string info;
    std::vector<unsigned int> direction; // stop ids in the order the bus visits them
    std::map<unsigned int, struct timetable> timetable;

    /**
     * @brief Get the direction of a vehicle
     * 
     * @param srcID     ID of the source stop
     * @param destID    ID of the destiny stop
     * @return 1        In case the direction is forward
     * @return 0        In case the direction is backwards
     * @return -1       In case of error (srcID or destID don't exist)
     */
    int getDirection(const unsigned int srcID, const unsigned int destID) {
        // WARNING : if the direction is 1 2 3, and the bus tries to move directly from 1 to 3 an error will occur

        for (size_t i = 0; i < direction.size(); i++) {
            if (srcID == direction[i])
                return 1;
            
            else if (destID == direction[i])
                return 0;
        }

        return -1;
    }

public: 



};


#endif
