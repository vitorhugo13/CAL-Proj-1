#ifndef EDGE_H
#define EDGE_H


#include <vector>
#include <limits>

#include "Time.h"


class Vertex;

#define INT_INF     std::numeric_limits<int>::max()
#define DOUBLE_INF  std::numeric_limits<double>::max()


enum Transportation { WALKING, BUS, SUBWAY, UNDEFINED };


// TODO: change these values
const double BUS_MULTIPLIER = 0.025;
const double SUBWAY_MULTIPLIER = 0.02;
const double FOOT_MULTIPLIER = 0.1;


class Edge {

protected:

    Vertex *srcVertex, *destVertex;
    double distance;        // distance between both vertices
    double tripTime[3];     // 0: foot; 1: bus; 2: subway

    Transportation chosenTransport;

    std::vector<std::string> busLines;
    std::vector<char> subwayLines;


public:

    Edge(Vertex *src, Vertex *dest);

    Vertex* getDest() {
        return destVertex;
    }    

    double getDistance();

    double getWalkingTime();

    double getBusTime();

    double getSubwayTime();

    double getBestTime();

    double getTime();

    Transportation getChosenTransport();



    friend class Graph;
    friend class Vertex;
};





#endif
