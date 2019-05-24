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

public:

    Vertex(int id, double x, double y);

    Coordinates getCoordinates() const;
    double getX() const;
    double getY() const;
    
    int getID() const;
    
    Vertex* getLastVertex() const;

    void addEdge(Edge *edge);

    size_t getNumEdges();

    Edge* getEdge(size_t index);
    
    bool operator<(Vertex const &vertex) const;

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


#endif
