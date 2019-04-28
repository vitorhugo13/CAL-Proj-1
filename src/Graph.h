#ifndef GRAPH_H
#define GRAPh_H

#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"

class Graph {

private:
    std::vector<Vertex *> vertexSet;

public:
    bool addVertex(const Vertex &vertex);
    bool addEdge(const Edge &edge);
    bool addVehicle(const Vehicle &vehicle);

};


#endif
