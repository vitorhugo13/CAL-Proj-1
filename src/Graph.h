#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>
#include <fstream>

#include "Vertex.h"
#include "Edge.h"

#include <vector>
#include <stack>
#include <limits>
#include <cmath>

class Graph {

private:
    std::vector<Vertex *> vertexSet;
    Time travelTime;

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
	
 
	std::stack<Vertex*> getPath(Vertex* lastVertex);
	std::string getDirections(std::stack<Vertex*> &path);
    Time getTime(){ return travelTime; }

	bool depthFirstSearch(Vertex* src, Vertex* dest);
	bool breadthFirstSearch(Vertex* src, Vertex* dest);

    /**
     * @brief Implementation of the dijkstra algorithm to claculate the quickest path between two vertexes
     * 
     * @param src 	Pointer to the initial vertex
     * @param dest 	Pointer to the final vertex
     */
    void dijsktraAlgorithm(Vertex* src, Vertex* dest);

	/**
	 * @brief Implementation of the A Star algorithm to calculate the quickest path between two vertexes
	 * 
	 * @param src 	Pointer to the initial vertex
	 * @param dest 	Pointer to the final vertex
	 */
	void A_star(Vertex* src, Vertex* dest);
};

#endif
