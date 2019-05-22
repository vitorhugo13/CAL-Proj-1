#ifndef EDGE_H
#define EDGE_H


#include <vector>

#include "Vertex.h"
#include "Vehicle.h"
#include "macros.h"

enum transportation { FOOT, BUS, SUBWAY }


// TODO: change these values
const double BUS_MULTIPLIER = 0.025;
const double SUBWAY_MULTIPLIER = 0.02;
const double FOOT_MULTIPLIER = 0.1;


class Edge {

protected:

    Vertex *srcVertex, *destVertex;
    double distance;        // distance between both vertices
    double tripTime[3];     // 0: foot; 1: bus; 2: subway

    transportation chosenTransportationMethod;

    std::vector<char> lines;

public:

    Edge(Vertex *src, Vertex *dest) {
        this->srcVertex = src;
        this->destVertex = dest;

        distance = src->getCoordinates().getDistance(dest->getCoordinates());

        tripTime[0] = distance * FOOT_MULTIPLIER;
        tripTime[1] = DOUBLE_INF;
        tripTime[2] = DOUBLE_INF;

        if (src->isBusStation() && dest->isBusStation()) {
            tripTime[1] = distance * BUS_MULTIPLIER;
        }

        if (src->getSubway() != nullptr && dest->getSubway() != nullptr) {

            std::vector<char> srcLines = src->getSubway()->getLines();

            for (size_t i = 0; i < srcLines.size(); i++) {
                if(dest->getSubway()->findLine(srcLines[i]) {
                    lines.push_back(srcLines[i]);
                }
            }

            if (!lines.empty()) {
                tripTime[2] = distance * SUBWAY_MULTIPLIER;
            }
        }
    }

    // TODO: implement funtions to get the best times
    // TODO: implement funtion to get foot time
    // TODO: implement funtion to get bus time
    // TODO: implement funtion to get subway time


    friend class Graph;
    friend class Vertex;

};


#endif
