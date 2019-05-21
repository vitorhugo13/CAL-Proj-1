#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"
#include "Coordinates.h"


enum VertexType { FOOT_VERTEX, BUS_STOP, SUBWAY_STATION };


class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge> paths;
    bool visited = false;
    Vertex *path = NULL;
    int queueIndex = 0;

public:

    Vertex(int id, double x, double y) {

        this->id = id;
        this->paths = {};
        this->coords = Coordinates(x, y);
        
    }
    
    vertexID getID() { return id; }

    bool operator<(const Vertex &obj) {
        return this->time < obj.time;
    }

    std::string getInfo() { return info; }
    Time getTime() { return time; }
    Vertex *getPath() { return path; }

    friend class Graph;
    friend class MutablePriorityQueue;
};


#endif
