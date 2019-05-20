#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>

#include "Vertex.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"

class Graph {

private:
    std::vector<Vertex *> vertexSet;

public:

    Graph() {
        vertexSet = {};
    }

    bool addVertex(const Vertex &vertex) {
        
    }
    bool addEdge(const Edge &edge);
    bool addVehicle(const Vehicle &vehicle);


    void loadVertexes(std::string vertexFile) {

    }

    void loadGraph(std::string vertexFile, std::string edgeFile, std::string vehicleFile) {



    }
};


#endif
