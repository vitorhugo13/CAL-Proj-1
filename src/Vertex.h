#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"
#include "Coordinates.h"


class Vertex {
    
private:
    static vertexID id = 0; // this might be removed if the stops have unique values ( info )
    std::string info;
    Coordinates coords;
    std::vector<Edge> paths;
    bool visited = false;
    Time time = Time(0);
    Vertex *path = NULL;
    int queueIndex = 0;

public:

    Vertex(std::string info, long int x, long int y) {
        this->id++;
        this->info = info;
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
