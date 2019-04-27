#ifndef VEHICLE_H
#define VEHICLE_H


#include <vector>
#include <map>
#include <string>

#include "macros.h"
#include "Time.h"



struct timetable {
    std::vector<Time> forward;
    std::vector<Time> backwards;
};


class Vehicle {

private:
    static vehicleID id;
    std::string info;
    std::vector<vertexID> direction; // stop ids in the order the bus visits them
    std::map<vertexID, struct timetable> timetable;

    /**
     * @brief Get the direction of a vehicle
     * 
     * @param srcID     ID of the source stop
     * @param destID    ID of the destiny stop
     * @return 1        In case the direction is forward
     * @return 0        In case the direction is backwards
     * @return -1       In case of error (srcID or destID don't exist)
     */
    short int getDirection(const vertexID srcID, const vertexID destID) {
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
    /**
     * @brief Get the Trip Time object
     * 
     * @param srcID 
     * @param destID 
     * @param currTime 
     * @return Time 
     */
    Time getTripTime(const vertexID srcID, const vertexID destID, Time currTime) {
        
        short int direction = getDirection(srcID, destID);

        std::map<vertexID, struct timetable>::iterator src_it, dest_it;
        src_it = timetable.find(srcID);
        dest_it = timetable.find(dest_it);
        if (timetable.end() == src_it || timetable.end() == dest_it) {
            return Time(TIME_LIMIT);
        }

        std::vector<Time> *src_times, *dest_times;
        if (0 == direction) {   // forward 
            
        }
        else if (1 == direction) {  // backwards

        }
        else {
            return Time(TIME_LIMIT);
        }
    }


};


#endif
