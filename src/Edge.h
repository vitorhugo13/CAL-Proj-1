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
	Edge(Vertex<T> *d, double w, int id);
	virtual Time getTravelTime(int startTime);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
class FootPath : public Edge<T> {

private:

public:
    FootPath(Vertex<T> *dest, double weigth, int id) : Edge<T>(dest, weigth, id) { }


};

template <class T>
class VehiclePath : public Edge<T> {

private:
    std::vector<Vehicle *> vehicles;
    unsigned int chosenVehicle;


public:

    VehiclePath( Vertex<T> *dest, double weigth, int id) : Edge<T>(dest, weigth, id) {
        vehicles = {};
        chosenVehicle = 0;
    }

};

#endif
