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
    Vertex *lastVertex = nullptr;
    int queueIndex = 0;
    Time time;

    bool busStop;
    SubwayStation* subway;

public:

    Vertex(int id, double x, double y);

    double getX() const;

    double getY() const;
    
    int getID() const;
    
    Coordinates getCoordinates();

    Vertex* Vertex::getLastVertex();


    void addEdge(Edge *edge);

    void setBusStop();

    bool isBusStop();

    void setSubway(SubwayStation *subway);

    SubwayStation *getSubway();

    size_t getNumEdges();

    Edge* getEdge(size_t index);
    
    bool operator<(Vertex const &vertex) const;

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


#endif
