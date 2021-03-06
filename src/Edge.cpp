#include <iostream>

#include "Edge.h"
#include "Graph.h"


Edge::Edge(Vertex *src, Vertex *dest, Type type) {
    this->srcVertex = src;
    this->destVertex = dest;
    this->type = type;
    draw = false;

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

void Edge::setDraw(bool draw) {
    this->draw = draw;
}

bool Edge::getDraw() {
    return draw;
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