#include <iostream>

#include "Graph.h"
#include "MutablePriorityQueue.h"



bool Graph::addEdge(Vertex* vertex, Edge *edge) {
        if (findVertex(vertex) == nullptr) {
            return false;
        }
        vertex->addEdge(edge);
        return true;
    }

    bool Graph::addVertex(Vertex *vertex) {
	    if (findVertex(vertex) != nullptr)
		    return false;
	    vertexSet.push_back(vertex);
	    return true;
    }

    Vertex* Graph::findVertex(const Vertex *vertex) const {
        return findVertex(vertex->getID());
    }

    Vertex* Graph::findVertex(const int vertexID) const {
        for (size_t i = 0; i < vertexSet.size(); i++) {
            if (vertexID == vertexSet[i]->getID()) {
                return vertexSet[i];
            }
        }
	    return nullptr;
    }


int Graph::loadVertexes(std::string filename) {

    std::fstream infile(filename);

    if (!infile.is_open()) {
        std::cerr << "Error opening vertex file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(infile, line);

    unsigned int line_num = std::stoi(line);

    std::string delimiter = ", ";

    for (size_t i = 0; i < line_num; i++) {
        std::getline(infile, line);
        line = line.substr(1, line.length() - 2);

        std::string info[3];
        size_t j = 0;
        size_t pos = 0;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            info[j++] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
        }
        info[j] = line;



        Vertex *v = new Vertex(std::stoi(info[0]), std::stod(info[1]), std::stod(info[2]));

        addVertex(v);
    }

    infile.close();

    return 0;
}

int Graph::loadEdges(std::string filename, Type edgeType) {

    std::fstream infile(filename);

    if (!infile.is_open()) {
        std::cerr << "Error opening edge file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(infile, line);

    unsigned int line_num = std::stoi(line);

    std::string delimiter = ", ";

    for (unsigned int i = 0; i < line_num; i++) {
        std::getline(infile, line);
        line = line.substr(1, line.length() - 2);

        size_t pos = line.find(delimiter);
        int srcID = std::stoi(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());

        int destID = std::stoi(line);
            
        Edge *e = new Edge(findVertex(srcID), findVertex(destID), edgeType);

        addEdge(findVertex(srcID), e);
    }

    infile.close();

    return 0;
}

Vertex* Graph::getVertex(size_t index) {
    if (index < vertexSet.size()) {
        return vertexSet[index];
    }
    return nullptr;
}

Vertex* Graph::findNearestVertex(Coordinates coords) {
    double distance = DOUBLE_INF;
    Vertex *vertex = nullptr;

    for (size_t i = 0; i < vertexSet.size(); i++) {
        if (vertexSet[i]->coords.getDistance(coords) <= distance) {
            vertex = vertexSet[i];
            distance = vertexSet[i]->coords.getDistance(coords);
        }
    }

    return vertex;
}

void Graph::dijsktraAlgorithm(const Vertex* src, const Vertex* dest) {

    for (size_t i = 0; i < vertexSet.size(); i++) {
        vertexSet[i]->time = Time(TIME_LIMIT);
        vertexSet[i]->lastVertex = nullptr;
        vertexSet[i]->visited = false;
    }
}
