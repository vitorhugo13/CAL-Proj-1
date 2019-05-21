#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"
#include "Coordinates.h"
#include "Vehicles.h"



class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge> paths;
    bool visited = false;
    Vertex *path = NULL;
    int queueIndex = 0;

    std::vector<BusStop*> busStops;
    std::vector<SubwayStation*> subwayStations;

public:

    Vertex(int id, double x, double y) {
        this->id = id;
        this->paths = {};
        this->coords = Coordinates(x, y);

        busStops = {};
        subwayStations = {};
    }
    
    vertexID getID() { return id; }
    Coordinates getCoordinates() { return coords; }

    bool operator<(const Vertex &obj) {
        return this->time < obj.time;
    }

    Vertex *getPath() { return path; }

    void addBus(BusStation &bus) {
        busStops.push_back(bus);
    }

    void addSubway(SubwayStation &subway) {
        subwayStations.push_back(subway);
    }

    friend class Graph;
    friend class MutablePriorityQueue;
};


#endif
