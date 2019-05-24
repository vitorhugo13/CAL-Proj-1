#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>
#include <fstream>

#include "Vertex.h"
#include "Edge.h"

#include <vector>
#include <queue>
#include <limits>
#include <cmath>

class Graph {

private:
    std::vector<Vertex *> vertexSet;

    bool addVertex(Vertex *vertex);
    bool addEdge(Vertex *vertex, Edge *edge);

public:

    int loadVertexes(std::string filename);
    int loadEdges(std::string filename, Type edgeType);	

    Vertex *findVertex(const Vertex *vertex) const;
    Vertex *findVertex(const int vertexID) const;

	Vertex *getVertex(size_t index);
	size_t getNumVertex() const { return vertexSet.size(); }

	Vertex *findNearestVertex(Coordinates coords);
 

    /**
     * @brief Implementation of the dijkstra algorithm to get the quickest path between two vertexes
     * 
     * @param src 	Pointer to the initial vertex
     * @param dest 	Pointer to the final vertex
     */
    void dijsktraAlgorithm(const Vertex* src, const Vertex* dest);

};

#endif
