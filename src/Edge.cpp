#include "Edge.h"
#include "Graph.h"

Edge::Edge(Vertex *src, Vertex *dest) {
    this->srcVertex = src;
    this->destVertex = dest;

    distance = src->getCoordinates().getDistance(dest->getCoordinates());

    tripTime[0] = distance * FOOT_MULTIPLIER;
    tripTime[1] = DOUBLE_INF;
    tripTime[2] = DOUBLE_INF;

    if (src->isBusStop() && dest->isBusStop()) {
        tripTime[1] = distance * BUS_MULTIPLIER;
    }

    if (src->getSubway() != nullptr && dest->getSubway() != nullptr) {

        std::vector<char> srcLines = src->getSubway()->getLines();

        for (size_t i = 0; i < srcLines.size(); i++) {
            if(dest->getSubway()->findLine(srcLines[i])) {
                lines.push_back(srcLines[i]);
            }
        }

        if (!lines.empty()) {
            tripTime[2] = distance * SUBWAY_MULTIPLIER;
        }
    }

    chosenTransport = UNDEFINED;
}


double Edge::getDistance() {
    return distance;
}

double Edge::getWalkingTime() {
    chosenTransport = WALKING;
    return tripTime[WALKING];
}

double Edge::getBusTime() {
    chosenTransport = BUS;
    return tripTime[BUS];
}

double Edge::getSubwayTime() {
    chosenTransport = SUBWAY;
    return tripTime[SUBWAY];
}

double Edge::getBestTime() {
    double bestTime = DOUBLE_INF;

    if (tripTime[WALKING] <= bestTime) {
        bestTime = tripTime[WALKING];
        chosenTransport = WALKING;
    }
    if (tripTime[BUS] <= bestTime) {
        bestTime = tripTime[BUS];
        chosenTransport = BUS;
    }
    if (tripTime[SUBWAY] <= bestTime) {
        bestTime = tripTime[SUBWAY];
        chosenTransport = SUBWAY;
    }

    return bestTime;
}

double Edge::getTime() {
    return tripTime[chosenTransport];
}

Transportation Edge::getChosenTransport() {
    return chosenTransport;
}