#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

class Coordinates {

private:
    double x;
    double y;

public:
    Coordinates();
    Coordinates(double x, double y);

    double getX() const;
    double getY() const;

    double getDistance(Coordinates coords) const;

    bool operator==(const Coordinates &c);
};


#endif
