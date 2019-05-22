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

    bool addVertex(const Vertex *vertex);
    bool addEdge(const Edge *edge);

public:

    void loadVertexes(std::string filename);
    void loadEdges(std::string filename);
    void loadBusStops(std::string filename);
    void loadSubwayStations(std::string filename);
    Vertex *findVertex(const Vertex *vertex) const;
    Vertex *findVertex(const int vertexID) const;
	int getNumVertex() const;
 
    void loadVertexes(std::string filename) {

        std::fstream infile(filename);
        std::string line;

        std::getline(infile, line);
        unsigned int line_num = stoi(line);

        std::string delimiter = ", ";

        for (unsigned int i = 0; i < line_num; i++) {
            std::sgetline(infile, line);
            line = line.substr(1, line.length - 2);

            std::string info[3];
            size_t i = 0;
            size_t pos = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                info[i++] = line.substr(0, pos);
            }

            Vertex *v = new Vertex(std::stoi(info[0]), std::stod(info[1]), std::stod(info[2]));

            addVertex(v);
        }

        infile.close();

    }

    void loadBusStops(std::string filename) {
        std::fstream infile(filename);
        std::string line;

        std::getline(infile, line);
        unsigned int line_num = stoi(line);

        std::string delimiter = ", ";

        for (unsigned int i = 0; i < line_num; i++) {
            std::sgetline(infile, line);
            line = line.substr(1, line.length - 2);

            size_t pos = line.find(delimiter);
            int vertexID = std::stoi(line.substr(0, pos));

            /*
            std::string info[7];
            size_t i = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                info[i] = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());
                info[i] = info[i].substr(1, info[i].length() - 2);
                i++;
            }

            BusStop *busStop = new BusStop(info[0], info[1], info[2], info[3], info[4], info[5], info[6]);
            */

            Vertex *vertex = findVertex(vertexID);

            vertex->setBusStop();
        }

        infile.close();
    }

    void loadSubwayStations(std::string filename) {
        std::fstream infile(filename);
        std::string line;

        std::getline(infile, line);
        unsigned int line_num = stoi(line);

        std::string delimiter = ", ";

        for (unsigned int i = 0; i < line_num; i++) {
            std::sgetline(infile, line);
            line = line.substr(1, line.length - 2);

            size_t pos = line.find(delimiter);
            int vertexID = std::stoi(line.substr(0, pos));

            std::string info[2];
            size_t i = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                info[i] = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());
                info[i] = info[i].substr(1, info[i].length() - 2);
                i++;
            }

            std::string token;
            std::vector<char> lines;
            while ((pos = info[1].find(delimiter)) != std::string::npos) {
                token = info[1].substr(0, pos);
                info[1].erase(0, pos + delimiter.length());
                lines.push_back(token[1]);
            }

            SubwayStation *subwayStation = new SubwayStation(info[0], lines);

            Vertex *vertex = findVertex(vertexID);

            vertex->addSubway(subwayStation);
        }

        infile.close();
    }

    void loadEdges(std::string filename) {

        std::fstream infile(filename);
        std::string line;

        std::getline(infile, line);
        unsigned int line_num = std::stoi(line);

        std::string delimiter = ", ";

        for (unsigned int i = 0; i < line_num; i++) {
            std::getline(infile, line);
            line = line.substr(1, line.length - 2);

            std::string info[2];
            size_t i = 0;
            size_t pos = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                info[i++] = line.substr(0, pos);
            }

            Edge *e = new Edge(std::stoi(info[0]), std::stoi(info[1]));

            addEdge(e);
        }

        infile.close();
    }

    bool addEdge(const Edge *edge) {
        Vertex *vertex;
        if ((vertex = findVertex(edge->srcVertex)) == nullptr) {
            return false;
        }
        vertex->addEdge(edge);
        return true;
    }

    bool addVertex(const Vertex *vertex) {
	    if (findVertex(vertex) != nullptr)
		    return false;
	    vertexSet.push_back(vertex);
	    return true;
    }

    Vertex *findVertex(const Vertex *vertex) const {
        return findVertex(vertex->getID());
    }

    Vertex *findVertex(const int vertexID) const {
        for (size_t i = 0; i < vertexSet.size(); i++) {
            if (vertexID == vertexSet[i]->getID()) {
                return vertexSet[i];
            }
        }
	    return nullptr;
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
