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
    /**
     * @brief 
     * 
     * @param filename that we are going to be getting the data
     * @return int 1 if error, 0 if success
     */
    int loadVertexes(std::string filename);

    /**
     * @brief 
     * 
     * @param filename of the file we are going to be getting the data
     * @param edgeType 
     * @return int 1 if error, 0 if success
     */
    int loadEdges(std::string filename, Type edgeType);	

    /**
     * @brief find a Vertex
     * 
     * @param vertex a pointer to a vertex
     * @return Vertex* 
     */
    Vertex *findVertex(const Vertex *vertex) const;

    /**
     * @brief we can find a vertex if we have its ID
     * 
     * @param vertexID that we want to find
     * @return Vertex* 
     */
    Vertex *findVertex(const int vertexID) const;

    /**
     * @brief Get the Vertex object
     * 
     * @param index of the object
     * @return Vertex* in that index
     */
	Vertex *getVertex(size_t index);

    /**
     * @brief Get the Number of Vertexs loaded
     * 
     * @return size_t num of vertex
     */
	size_t getNumVertex() const { return vertexSet.size(); }

    /**
     * @brief 
     * 
     * @param coordinates of the vertex we want to find
     * @return Vertex* nearest or in that coordinates
     */
	Vertex *findNearestVertex(Coordinates coords);
	
    /**
     * @brief Get the Path object
     * 
     * @param lastVertex of the path
     * @return std::stack<Vertex*> vertexes in the path
     */
	std::stack<Vertex*> getPath(Vertex* lastVertex);
    /**
     * @brief Get the Directions object
     * 
     * @param path
     * @param travelTime - were we are going to put the final time
     * @return std::string string with the Direction like Id - Type - OtherId
     */
	std::string getDirections(std::stack<Vertex*> &path, Time &travelTime);
    /**
     * @brief Get the Time object
     * 
     * @return duraction time of the travel
     */
    Time getTime(){ return travelTime; }

    /**
     * @brief 
     * 
     * @param source vertex
     * @param destiny vertex
     * @return true if sucessfull
     * @return false otherwise
     */
	bool breadthFirstSearch(Vertex* src, Vertex* dest);

    /**
     * @brief Implementation of the dijkstra algorithm to calculate the quickest path between two vertexes
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
