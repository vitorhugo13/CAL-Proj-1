#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "macros.h"
#include "Edge.h"



template <class T>
class Vertex {
    
private:
    static vertexID id;
    std::string info;
    std::vector<Edge<T>> paths;
    int cost = INF;

public:


};


#endif
