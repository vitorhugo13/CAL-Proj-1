#ifndef EDGE_H
#define EDGE_H


#include <vector>

#include "Vertex.h"
#include "Vehicle.h"
#include "Time.h"


class Edge {

protected:
    Vertex *srcVertex, *destVertex;

public:
    Edge(Vertex *src, Vertex *dest) {
        this->srcVertex = src;
        this->destVertex = dest;
    }
    virtual Time getTravelTime(int startTime);

};


class FootPath : public Edge {

private:
    Time travelTime;

public:
    FootPath(Vertex *src, Vertex *dest, Time travelTime) : Edge(src, dest) {
        this->travelTime = travelTime;
    }
    Time getTravelTime(int startTime) { return travelTime; }

};


class VehiclePath : public Edge {

private:

    std::vector<Vehicle *> vehicles;
    unsigned int chosenVehicle;


public:

    VehiclePath(Vertex *src, Vertex *dest) : Edge(src, dest) {
        vehicles = {};
        chosenVehicle = 0;
    }

    Time getTravelTime(int startTime) {
        
        Time minTime(TIME_LIMIT);

        for (size_t i = 0; i < vehicles.size(); i++) {
            Time tmpTime = vehicles[i]->getTripTime(srcVertex->getID(), destVertex->getID(), startTime);

            if (tmpTime < minTime) {
                minTime = tmpTime;
                chosenVehicle = i;
            }
        }

        return minTime;
    }

};

#endif
