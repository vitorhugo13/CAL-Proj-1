#ifndef EDGE_H
#define EDGE_H

#include <vector>

#include "Vertex.h"



template <class T>
class Edge {

protected:
    Vertex<T> *srcVertex, *destVertex;

public:
    virtual int getTravelTime(int currTime);

};


template <class T>
class FootPath : public Edge<T> {

private:
    int travelTime;

public:
    int getTravelTime(int currTime) { return travelTime; }

};


template <class T>
class VehiclePath : public Edge<T> {

private:
    std::vector<Vehicle *> vehicles;

public:
    int getTravelTime(int currTime) {

        
    }

};

#endif
