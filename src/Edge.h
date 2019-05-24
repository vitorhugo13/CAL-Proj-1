#ifndef EDGE_H
#define EDGE_H


#include <vector>
#include <limits>

#include "Time.h"


class Vertex;

#define INT_INF     std::numeric_limits<int>::max()
#define DOUBLE_INF  std::numeric_limits<double>::max()


enum Type { WALKING, BUS, SUBWAY };


class Edge {

protected:

    Vertex *destVertex;
    
    double distance;
    Time time;

    Type type;

public:

    Edge(Vertex *src, Vertex *dest, Type type);

    Vertex* getDest() {
        return destVertex;
    }    

    double getDistance();
    Time getTime();

    Type getEdgeType();

    friend class Graph;
    friend class Vertex;
};





#endif
