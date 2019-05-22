#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "Edge.h"
#include "Coordinates.h"
#include "Vehicles.h"
#include "MutablePriorityQueue.h"



class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge*> paths;
    bool visited = false;
    Vertex *path = NULL;
    int queueIndex = 0;
    Time time;


    bool busStop;
    SubwayStation* subway;

public:

    Vertex(int id, double x, double y);
    
    int getID() const {
        return id;
    }
    
    Coordinates getCoordinates() {
        return coords;
    }

    Vertex *getPath() { return path; }

    void addEdge(Edge *edge) {
        paths.push_back(edge);
    }

    void setBusStop() {
        busStop = true;
    }

    bool isBusStop() {
        return busStop;
    }

    void setSubway(SubwayStation *subway) {
        this->subway = subway;
    }

    SubwayStation *getSubway() {
        return subway;
    }

    bool operator<(Vertex const &vertex) const;

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


#endif
