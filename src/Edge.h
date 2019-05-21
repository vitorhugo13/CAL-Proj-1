#ifndef EDGE_H
#define EDGE_H


#include <vector>

#include "Vertex.h"
#include "Vehicle.h"
#include "Time.h"

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Edge {
	int id;
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	virtual Time getTravelTime(int startTime);
	friend class Graph<T>;
	friend class Vertex<T>;
};
/*
class FootPath : public Edge {

private:
    Time travelTime;

public:
    FootPath(Vertex<T> *dest, double weigth, Time travelTime) : Edge(dest, weigth) {
        this->travelTime = travelTime;
    }
    Time getTravelTime(int startTime) { return travelTime; }

};


class VehiclePath : public Edge<T> {

private:
	int id;
    std::vector<Vehicle *> vehicles;
    unsigned int chosenVehicle;


public:

    VehiclePath(Vertex<T> *dest, double weigth) : Edge(dest, weigth) {
        vehicles = {};
        chosenVehicle = 0;
    }

    Time getTravelTime(int startTime) {
        
        Time minTime(TIME_LIMIT);

        for (size_t i = 0; i < vehicles.size(); i++) {
            Time tmpTime = vehicles[i]->getTripTime(id, destVertex->getID(), startTime);

            if (tmpTime < minTime) {
                minTime = tmpTime;
                chosenVehicle = i;
            }
        }

        return minTime;
    }

};*/

#endif
