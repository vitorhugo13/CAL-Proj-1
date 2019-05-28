#include <iostream>
#include <queue>
#include <chrono>
#include <iomanip>

#include "Graph.h"
#include "MutablePriorityQueue.h"

bool Graph::addEdge(Vertex *vertex, Edge *edge)
{
    if (findVertex(vertex) == nullptr)
    {
        return false;
    }
    vertex->addEdge(edge);
    return true;
}

bool Graph::addVertex(Vertex *vertex)
{
    if (findVertex(vertex) != nullptr)
        return false;
    vertexSet.push_back(vertex);
    return true;
}

Vertex *Graph::findVertex(const Vertex *vertex) const
{
    return findVertex(vertex->getID());
}

Vertex *Graph::findVertex(const int vertexID) const
{
    for (size_t i = 0; i < vertexSet.size(); i++)
    {
        if (vertexID == vertexSet[i]->getID())
        {
            return vertexSet[i];
        }
    }
    return nullptr;
}

int Graph::loadVertexes(std::string filename)
{

    std::fstream infile(filename);

    if (!infile.is_open())
    {
        std::cerr << "Error opening vertex file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(infile, line);

    unsigned int line_num = std::stoi(line);

    std::string delimiter = ", ";

    for (size_t i = 0; i < line_num; i++)
    {
        std::getline(infile, line);
        line = line.substr(1, line.length() - 2);

        std::string info[3];
        size_t j = 0;
        size_t pos = 0;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            info[j++] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());//ver 
        }
        info[j] = line;

        Vertex *v = new Vertex(std::stoi(info[0]), std::stod(info[1]), std::stod(info[2]));

        addVertex(v);
    }

    infile.close();

    return 0;
}

int Graph::loadEdges(std::string filename, Type edgeType)
{

    std::fstream infile(filename);

    if (!infile.is_open())
    {
        std::cerr << "Error opening edge file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(infile, line);

    unsigned int line_num = std::stoi(line);

    std::string delimiter = ", ";

    for (unsigned int i = 0; i < line_num; i++)
    {
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

Vertex *Graph::getVertex(size_t index)
{
    if (index < vertexSet.size())
    {
        return vertexSet[index];
    }
    return nullptr;
}

Vertex *Graph::findNearestVertex(Coordinates coords)
{
    double distance = DOUBLE_INF;
    Vertex *vertex = nullptr;

    for (size_t i = 0; i < vertexSet.size(); i++)
    {
        if (vertexSet[i]->coords.getDistance(coords) <= distance)
        {
            vertex = vertexSet[i];
            distance = vertexSet[i]->coords.getDistance(coords);
        }
    }

    return vertex;
}

void Graph::dijsktraAlgorithm(Vertex *src, Vertex *dest)
{

    //auto begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < vertexSet.size(); i++)
    {
        vertexSet[i]->setTime(Time(TIME_LIMIT));
        vertexSet[i]->setLastVertex(nullptr);
        vertexSet[i]->setVisited(false);
        vertexSet[i]->setLastEdgeType(UNDEFINED);
    }

    src->setTime(Time("00:00"));
    MutablePriorityQueue<Vertex> queue;

    queue.insert(src);

    Vertex *v, *w;

    while (!queue.empty())
    {
        v = queue.extractMin();

        if (v->getID() == dest->getID())
        {
            break;
        }

        Time oldTime, newTime;
        for (size_t i = 0; i < v->getNumEdges(); i++)
        {
            Edge edge = *v->getEdge(i);
            w = edge.getDest();
            oldTime = w->getTime();
            newTime = v->getTime() + edge.getTime();

            if (oldTime > newTime)
            {
                w->setTime(newTime);
                w->setLastVertex(v);
                w->setLastEdgeType(edge.getEdgeType());

                if (!w->getVisited())
                    queue.insert(w);
                else
                    queue.decreaseKey(w);

                w->setVisited(true);
            }
        }
    }

    /*
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
    */
}

std::stack<Vertex *> Graph::getPath(Vertex *lastVertex)
{

    std::stack<Vertex *> path;

    Vertex *vertex = lastVertex;

    while (vertex != nullptr)
    {
        path.push(vertex);
        vertex = vertex->getLastVertex();
    }

    return path;
}

// TODO: get travel time - DONE
std::string Graph::getDirections(std::stack<Vertex *> &path, Time &travelTime)
{

    if (path.empty())
    {
        std::cerr << "No path is present!" << std::endl;
        return "No path is present!";
    }

    Vertex *v = path.top();
    Vertex *w;
    path.pop();

    std::string explainedPath = "";

    while (!path.empty())
    {
        w = path.top();
        path.pop();

        explainedPath += std::to_string(v->getID()) + "---";

        switch (v->getLastEdgeType())
        {
        case WALKING:
            explainedPath += "WALKING";
            break;
        case BUS:
            explainedPath += "BUS";
            break;
        case SUBWAY:
            explainedPath += "SUBWAY";
            break;
        default:
            break;
        }

        explainedPath += "--->" + std::to_string(w->getID()) + "\n";

        v = w;
    }
    travelTime = w->getTime();

    return explainedPath;
}

bool Graph::breadthFirstSearch(Vertex *src, Vertex *dest)
{

    // base case
    if (src->getID() == dest->getID())
        return true;

    // mark all vertexes as not visited
    for (size_t i = 0; i < vertexSet.size(); i++)
    {
        vertexSet[i]->setVisited(false);
    }

    std::queue<Vertex *> queue;

    src->setVisited(true);
    queue.push(src);

    while (!queue.empty())
    {

        Vertex *vertex = queue.front();
        queue.pop();

        for (size_t i = 0; i < vertex->getNumEdges(); i++)
        {
            Vertex *adj = vertex->getEdge(i)->getDest();

            if (adj->getID() == dest->getID())
                return true;

            if (!adj->getVisited())
            {
                adj->setVisited(true);
                queue.push(adj);
            }
        }
    }

    return false;
}

void Graph::A_star(Vertex *src, Vertex *dest)
{

    for (size_t i = 0; i < vertexSet.size(); i++)
    {
        vertexSet[i]->setTime(Time(TIME_LIMIT));
        vertexSet[i]->setLastVertex(nullptr);
        vertexSet[i]->setVisited(false);
        vertexSet[i]->setLastEdgeType(WALKING);
    }

    src->setTime(Time("0"));
    MutablePriorityQueue<Vertex> queue;

    queue.insert(src);

    Vertex *v, *w;

    while (!queue.empty())
    {
        v = queue.extractMin();

        if (v->getID() == dest->getID())
        {
            dest->setTime(dest->getTime() + src->getAverageTime(dest));
            break;
        }

        Time oldTime, newTime;
        for (size_t i = 0; i < v->getNumEdges(); i++)
        {
            Edge edge = *v->getEdge(i);
            w = edge.getDest();
            oldTime = w->getTime();
            newTime = v->getTime() + edge.getTime() - v->getAverageTime(dest) + w->getAverageTime(dest);

            if (oldTime > newTime)
            {
                w->setTime(newTime);
                w->setLastVertex(v);
                w->setLastEdgeType(edge.getEdgeType());

                if (!w->getVisited())
                    queue.insert(w);
                else
                    queue.decreaseKey(w);

                w->setVisited(true);
            }
        }
    }
}
