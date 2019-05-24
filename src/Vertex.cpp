#include "Vertex.h"



Vertex::Vertex(int id, double x, double y) {
    this->id = id;
    paths = {};
    coords = Coordinates(x, y);

    time = Time(TIME_LIMIT);
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
    
Coordinates Vertex::getCoordinates() const {
    return coords;
}

Vertex* Vertex::getLastVertex() const {
    return lastVertex;
}

void Vertex::addEdge(Edge *edge) {
    paths.push_back(edge);
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

