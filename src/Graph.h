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
    Vertex *findVertex(const Vertex &vertex) const;
    bool addVertex(const Vertex &vertex);
    bool addEdge(const Edge &edge);
    bool addVehicle(const Vehicle &vehicle);
	int getNumVertex() const;

    Vertex* findVertex(const std::string &v);
    



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



#endif
