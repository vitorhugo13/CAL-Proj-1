#ifndef GRAPH_H
#define GRAPh_H

#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

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
/*




    



    //dist é o time
    //Implementação do algoritmo de dijsktra

    void dijsktraAlgorithm(const std::string &src, const std::string &dest){



        for(unsigned int i=0;i<vertexSet.size();i++){
		    vertexSet[i]->path=NULL;    //o que esta parte do algoritmo faz é percorrer o vertexSet todo
		    vertexSet[i]->time=TIME_LIMIT;		//mete o path a null, a distancia como infinito e visited a false
		    vertexSet[i]->visited=false;// assim todos os pontos ficam em igualdade
	    }

	    Vertex* startVertex=this->findVertex(src); 
        if(!startVertex){
		    return;
        }
        startVertex->time=0;

	    MutablePriorityQueue<Vertex> q;
	    startVertex->visited=true;
	    q.insert(startVertex);

        while(!q.empty()){
            Vertex* v=q.extractMin();

            for(size_t i=0;i<v->paths.size();i++){
			    Edge edge=v->paths[i];
			    Vertex* w=v->paths[i]->time;
                
                if(edge.getTravelTime< w->time){
                        w->time=edge.getTravelTime;
                        w->path=v;
                }
		    }
        }
	}

	
    
    //quando for encontrado o vertex de destino o algoritmo não pode percorrer mais.

};

*/

#endif
