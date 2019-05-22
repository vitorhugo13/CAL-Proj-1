#ifndef GRAPH_H
#define GRAPh_H

#include <vector>
#include <string>
#include <fstream>

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
