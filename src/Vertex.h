#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"
#include "Coordinates.h"
#include "Vehicles.h"


template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge*> paths;
    bool visited = false;
    Vertex *path = NULL;
    int queueIndex = 0;


    bool isBusStop;
    SubwayStation* subway;

public:

    Vertex(int id, double x, double y) {
        this->id = id;
        this->paths = {};
        this->coords = Coordinates(x, y);

        isBusStop = false;
        subway = nullptr;
    }
    
    vertexID getID() { return id; }
    Coordinates getCoordinates() { return coords; }

    bool operator<(const Vertex &obj) {
        return this->time < obj.time;
    }

    Vertex *getPath() { return path; }

    void addEdge(const Edge *edge) {
        paths.push_back(edge);
    }

    void setBusStop() {
        isBusStop = true;
    }

    bool isBusStop() {
        return isBusStop;
    }

    void setSubway(SubwayStation *subway) {
        this->subway = subway;
    }

    SubwayStation *getSubway() {
        return subway;
    }

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue;
};


#endif
