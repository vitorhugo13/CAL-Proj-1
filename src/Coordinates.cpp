#include "Coordinates.h"



Coordinates::Coordinates() {
    x = 0; y = 0;
}

Coordinates::Coordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

double Coordinates::getDistance(Coordinates coords) const {
    return sqrt(pow(this->y - coords.y, 2) + pow(this->x - coords.x, 2));
}

double Coordinates::getX() const {
    return x;
}

double Coordinates::getY() const {
    return y;
}

bool Coordinates::operator==(const Coordinates &c) {
    return(this->x == c.getX() && this->y == c.getY());
}
