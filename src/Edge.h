#ifndef EDGE_H
#define EDGE_H


#include <vector>

#include "Vertex.h"
#include "Vehicle.h"


class Edge {

protected:

    Vertex *srcVertex, *destVertex;
    double weight;

public:

    Edge(Vertex *src, Vertex *dest) {
        this->srcVertex = src;
        this->destVertex = dest;

        weight = srcVertex->getCoordinates().getDistance(destVertex->getCoordinates());
    }


    friend class Graph;
    friend class Vertex;

};


#endif
