#include "Edge.h"
#include "Graph.h"

Edge::Edge(Vertex *src, Vertex *dest) {
    this->destVertex = dest;

    distance = src->getCoordinates().getDistance(dest->getCoordinates());

    tripTime[0] = Time(distance * FOOT_MULTIPLIER);
    tripTime[1] = Time(TIME_LIMIT);
    tripTime[2] = Time(TIME_LIMIT);

    if (src->isBusStop() && dest->isBusStop()) {
        tripTime[1] = Time(distance * BUS_MULTIPLIER);
    }

    if (src->getSubway() != nullptr && dest->getSubway() != nullptr) {

        std::vector<char> srcLines = src->getSubway()->getLines();

        for (size_t i = 0; i < srcLines.size(); i++) {
            if(dest->getSubway()->findLine(srcLines[i])) {
                subwayLines.push_back(srcLines[i]);
            }
        }

        if (!subwayLines.empty()) {
            tripTime[2] = Time(distance * SUBWAY_MULTIPLIER);
        }
    }

    chosenTransport = UNDEFINED;
}


double Edge::getDistance() {
    return distance;
}

Time Edge::getWalkingTime() {
    chosenTransport = WALKING;
    return tripTime[WALKING];
}

Time Edge::getBusTime() {
    chosenTransport = BUS;
    return tripTime[BUS];
}

Time Edge::getSubwayTime() {
    chosenTransport = SUBWAY;
    return tripTime[SUBWAY];
}

Time Edge::getBestTime() {
    Time bestTime(TIME_LIMIT);

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

Time Edge::getTime() {
    return tripTime[chosenTransport];
}

Transportation Edge::getChosenTransport() {
    return chosenTransport;
}