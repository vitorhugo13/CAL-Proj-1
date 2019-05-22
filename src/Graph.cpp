#include <iostream> // TODO: remove after debug
#include <iomanip>


#include "Graph.h"
#include "MutablePriorityQueue.h"



bool Graph::addEdge(Edge *edge) {
        Vertex *vertex;
        if ((vertex = findVertex(edge->srcVertex)) == nullptr) {
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

        Vertex *v = new Vertex(std::stoi(info[0]), std::stod(line), std::stod(info[2]));

        addVertex(v);
    }

    infile.close();

    return 0;
}

    int Graph::loadBusStops(std::string filename) {
        std::fstream infile(filename);

        if (!infile.is_open()) {
            std::cerr << "Error opening bus stops file!" << std::endl;
            return 1;
        }

        std::string line;
        std::getline(infile, line);

        unsigned int line_num = std::stoi(line);

        std::string delimiter = ", ";

        for (size_t i = 0; i < line_num; i++) {
            std::getline(infile, line);
            line = line.substr(1, line.length() - 2);

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

            BusStop *busStop = new BusStop(info[0], line, info[2], info[3], info[4], info[5], info[6]);
            */

            Vertex *vertex = findVertex(vertexID);

            vertex->setBusStop();
        }

        infile.close();

        return 0;
    }

    int Graph::loadSubwayStations(std::string filename) {
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

            size_t pos = line.find(delimiter);
            int vertexID = std::stoi(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());


            pos = line.find(delimiter);
            std::string stationName = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            line = line.substr(1, line.length() - 2);


            std::vector<char> lines;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                lines.push_back(line.substr(0, pos)[1]);
                line.erase(0, pos + delimiter.length());
            }
            lines.push_back(line[1]);

            SubwayStation *subwayStation = new SubwayStation(stationName, lines);

            Vertex *vertex = findVertex(vertexID);

            vertex->setSubway(subwayStation);
        }

        infile.close();

        return 0;
    }

    int Graph::loadEdges(std::string filename) {

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
            
            Edge *e = new Edge(findVertex(srcID), findVertex(destID));

            addEdge(e);
        }

        infile.close();

        return 0;
    }