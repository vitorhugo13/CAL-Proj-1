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

/**
 * @brief 
 * 
 */
class Vehicle {

private:

    static vehicleID id = 0;
    std::string info;
    std::vector<vertexID> route; // stop ids in the order the bus visits them
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

        for (size_t i = 0; i < route.size(); i++) {
            if (srcID == route[i])
                return 1;
            
            else if (destID == route[i])
                return 0;
        }

        return -1;
    }

    /**
     * @brief   This function finds the index of the next departure of a vehicle given a start time.
     *          It is based on the binary-search algorithm, however some conditions were added, because the 
     *          startTime value parsed might not be an element of the vector, thus the name of the function 
     *          (nearest time).
     * 
     * @param timetable Pointer to an orderer vector of Time objects, these represent the departure times
     * @param startTime Start time
     * @return size_t   Index of the next departure in the vector
     */
    size_t findNearestTimeIndex(std::vector<Time> *timetable, Time startTime) {
        size_t mid, left = 0;
        size_t size = (*timetable).size();
        size_t right = size;
        
        while (left < right) {
            mid = left + (right - left)/2;
            if (startTime > (*timetable)[mid]) {
                left = mid + 1;
            }
            else if (startTime < (*timetable)[mid]) {                                        
                right = mid;
            }
            else if (left == mid && mid == right) {
                return mid;
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

public:

    /**
     * @brief Vehicle constructor
     * 
     * @param info          Vehicle information
     * @param route         Stops made by the vehicle, in the real order
     * @param timetable     Time of departure for each stop, in both directions of the route
     */
    Vehicle(std::string info, std::vector<vertexID> route, std::map<vertexID, struct timetable> timetable) {
        this->id++;
        this->info = info;
        this->route = route;
        this->timetable = timetable;
    }

    /**
     * @brief   Returns the duration of a trip between two points, including the wait time. If, by any case, 
     *          an error occurs, the function will return a Time object with the maximum possible value.
     * 
     * @param srcID     Beggining stop
     * @param destID    Destination stop
     * @param currTime  Current time
     * @return Time     Duration of the trip
     */
    Time getTripTime(const vertexID srcID, const vertexID destID, Time startTime) {
        
        // get src and dest iterators
        std::map<vertexID, struct timetable>::iterator src_it, dest_it;
        src_it = timetable.find(srcID);
        dest_it = timetable.find(dest_it);
        if (timetable.end() == src_it || timetable.end() == dest_it) {
            return Time(TIME_LIMIT);
        }

        // get src and dest timetables according to the bus direction
        short int direction = getDirection(srcID, destID);

        std::vector<Time> *src_times, *dest_times;
        if (0 == direction) {   // forward 
            src_times = &src_it->second.forward;
            dest_times = &dest_it->second.forward;
        }
        else if (1 == direction) {  // backwards
            src_times = &src_it->second.backwards;
            dest_times = &dest_it->second.backwards;
        }
        else {
            return Time(TIME_LIMIT);
        }

        // get src and dest bus times index
        size_t index = findNearestTimeIndex(src_times, startTime);

        // returns wait time plus trip time
        return (*src_times[index] - startTime) + (*dest_times[index]) - (*src_times[index]);
    }


};


#endif
