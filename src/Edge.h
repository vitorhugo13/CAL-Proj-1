#ifndef EDGE_H
#define EDGE_H


#include <vector>

#include "Vertex.h"
#include "Vehicle.h"
#include "Time.h"

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Edge {
	int id;
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w, int id);
	virtual Time getTravelTime(int startTime);
	friend class Graph<T>;
	friend class Vertex<T>;
};


#endif
