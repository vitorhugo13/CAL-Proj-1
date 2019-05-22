#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>

#include "Vertex.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>

<<<<<<< HEAD
class Graph {

private:
    std::vector<Vertex *> vertexSet;

public:
    Vertex *findVertex(const Vertex &vertex) const;
    bool addVertex(const Vertex &vertex);
    bool addEdge(const Edge &edge);
    bool addVehicle(const Vehicle &vehicle);
	int getNumVertex() const;

    Vertex* findVertex(const std::string &v);
    



    //dist é o time
    //Implementação do algoritmo de dijsktra

    void dijsktraAlgorithm(const std::string &src, const std::string &dest){

=======
template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;
>>>>>>> 5c49f1d4f5d3a8caaf5db925c0dd9e10ac789254

const constexpr double BUS_TIME_MULTIPLIER = 0.025;
const constexpr double SUBWAY_TIME_MULTIPLIER = 0.02;
const constexpr double WALK_TIME_MULTIPLIER = 0.1;

const constexpr double BUS_PRICE = 1.20;
const constexpr double SUBWAY_PRICE = 1.70;
const constexpr double WALK_PRICE = 0.0;

const constexpr double DEFAULT_TRANSBORD_TIME = 5.0;

const string TIME_MODE = "time";
const string PRICE_MODE = "price";

const string BUS = "bus";
const string WALK = "walk";
const string SUBWAY = "subway";

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool addVehicle(const Vehicle &vehicle);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;
	bool removeEdge(const T &sourc, const T &dest);
	bool removeVertex(const T &in);
	vector<T> dfs() const;
	void dfsVisit(Vertex<T> *v, vector<T> & res) const;
	vector<T> bfs(const T & source) const;
	vector<T> topsort() const;
	bool isDAG() const;
	int maxNewChildren(const T & source, T &inf) const ;
	Vertex<T> *initSingleSource(const T &origin);
	bool dfsIsDAG(Vertex<T> *v) const;
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	void dijkstraShortestPath(const T &s);
	void dijkstraShortestPathOld(const T &s);
	void unweightedShortestPath(const T &s);
	vector<T> getPath(const T &origin, const T &dest) const;

};


#endif
