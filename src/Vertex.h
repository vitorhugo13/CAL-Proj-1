#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "Edge.h"
#include "Coordinates.h"
#include "MutablePriorityQueue.h"



class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge*> paths;
    
    bool visited = false;
    Vertex *lastVertex = nullptr;
    int queueIndex = 0;
    Time time;
    Type lastEdgeType = WALKING;
    

public:

    Vertex(int id, double x, double y);
    Vertex() { }
    Coordinates getCoordinates() const;
    double getX() const;
    double getY() const;
    
    int getID() const;

    Time getTime() const;
    void setTime(Time newTime);
    
    Vertex* getLastVertex() const;
    void setLastVertex(Vertex* vertex);

    bool getVisited() const;
    void setVisited(bool visited);

    Type getLastEdgeType() const;
    void setLastEdgeType(Type edgeType);

    /**
     * @brief Calculate the time that would take to travel from one vertex to another by subway and in a straight line
     * 
     * @param vertex    Pointer to the vertex to travel to
     * @return Time     Time of the trip
     */
    Time getAverageTime(Vertex const *vertex) const;

    void addEdge(Edge *edge);

    size_t getNumEdges();

    Edge* getEdge(size_t index);
    
    bool operator<(Vertex const &vertex) const;

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


#endif
