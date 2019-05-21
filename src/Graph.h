#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>
#include <fstream>

#include "Vertex.h"
#include "Edge.h"
#include "MutablePriorityQueue.h"


class Graph {

private:
    std::vector<Vertex *> vertexSet;

    void addVertex(const Vertex &vertex);
    bool addEdge(const Edge &edge);

public:
    void loadVertexes(std::string filename);
    Vertex *findVertex(const Vertex &vertex) const;
    Vertex *findVertex(const int id) const;
	int getNumVertex() const;

    
    void loadVertexes(std::string filename) {

        std::fstream infile(filename);
        std::string line;

        getline(infile, line);
        unsigned int line_num = stoi(line);

        std::string delimiter = ",";

        for (unsigned int i = 0; i < line_num; i++) {
            getline(infile, line);
            line = line.substr(1, line.length - 2);

            std::string info[3];
            size_t i = 0;
            size_t pos = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                info[i++] = line.substr(0, pos);
            }

            Vertex *v = new Vertex(stoi(info[0]), stod(info[1]), stod(info[2]));

            addVertex(v);
        }
    }

    void addVertex(const Vertex &vertex) {
        vertexSet.insert(std::lower_bound(vertexSet.begin(), vertexSet.end(), vertex));
    }

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
