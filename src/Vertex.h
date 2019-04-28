#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"


class Vertex {
    
private:
    static vertexID id = 0;
    std::string info;
    std::vector<Edge> paths;
    bool visited = false;
    Time time(0);
    Vertex *path = NULL;
    int queueIndex = 0;

public:

    Vertex(std::string info) {
        this->id++;
        this->info = info;
        this->paths = {};
    }
    
    vertexID getID() { return id; }

    bool operator<(const Vertex &obj) {
        return this->time < obj.time;
    }

    std::string getInfo() { return info; }

};


#endif
