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
