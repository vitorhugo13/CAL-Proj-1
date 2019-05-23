#include "Vertex.h"



Vertex::Vertex(int id, double x, double y) {
    this->id = id;
    paths = {};
    coords = Coordinates(x, y);

    time = Time(TIME_LIMIT);
    busStop = false;
    subway = nullptr;
}

bool Vertex::operator<(const Vertex &vertex) const {
    return this->time < vertex.time;
}

double Vertex::getX() const {
        return coords.getX();
}

double Vertex::getY() const {
    return coords.getY();
}
    
int Vertex::getID() const {
    return id;
}
    
Coordinates Vertex::getCoordinates() {
    return coords;
}

Vertex* Vertex::getLastVertex() {
    return lastVertex;
}

void Vertex::addEdge(Edge *edge) {
    paths.push_back(edge);
}

void Vertex::setBusStop() {
    busStop = true;
}

bool Vertex::isBusStop() {
    return busStop;
}

void Vertex::setSubway(SubwayStation *subway) {
    this->subway = subway;
}


SubwayStation* Vertex::getSubway() {
    return subway;
}

size_t Vertex::getNumEdges() {
    return paths.size();
}

Edge* Vertex::getEdge(size_t index) {
    if (index < paths.size()) {
        return paths[index];
    }
    return nullptr;
}

