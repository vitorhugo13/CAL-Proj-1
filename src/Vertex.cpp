#include "Vertex.h"



Vertex::Vertex(int id, double x, double y) {
    this->id = id;
    coords = Coordinates(x, y);

    time = Time(TIME_LIMIT);
    draw = false;
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

Edge* Vertex::getLastEdge() const {
    return lastEdge;
}

void Vertex::setLastEdge(Edge* edge) {
    lastEdge = edge;
}
    
bool Vertex::getVisited() const {
    return visited;
}
    
void Vertex::setVisited(bool visited) {
    this->visited = visited;
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

Time Vertex::getTime() const {
    return time;
}

void Vertex::setTime(Time newTime) {
    time = newTime;
}

Time Vertex::getAverageTime(Vertex const *vertex) const {
    return Time(this->coords.getDistance(vertex->getCoordinates()) * SUBWAY_MULTIPLIER);
}

void Vertex::setDraw(bool draw) {
    this->draw = draw;
}

bool Vertex::getDraw() {
    return draw;
}
