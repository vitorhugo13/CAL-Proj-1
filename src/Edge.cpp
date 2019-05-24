#include <iostream>

#include "Edge.h"
#include "Graph.h"


// TODO: change these values
const double BUS_MULTIPLIER = 0.025;
const double SUBWAY_MULTIPLIER = 0.02;
const double WALKING_MULTIPLIER = 0.1;



Edge::Edge(Vertex *src, Vertex *dest, Type type) {
    this->destVertex = dest;
    this->type = type;

    distance = src->getCoordinates().getDistance(dest->getCoordinates());

    switch (type) {
        case WALKING:
            time = Time(distance * WALKING_MULTIPLIER);
            break;
        case BUS:
            time = Time(distance * BUS_MULTIPLIER);
            break;
        case SUBWAY:
            time = Time(distance * SUBWAY_MULTIPLIER);
            break;
        default:
            std::cerr << "Incorrect edge type!" << std::endl;
            return;
    }
}


double Edge::getDistance() {
    return distance;
}

Time Edge::getTime() {
    return time;
}

Type Edge::getEdgeType() {
    return type;
}