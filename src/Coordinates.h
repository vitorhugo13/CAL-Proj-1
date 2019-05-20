#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

class Coordinates {

private:
    double x, y;

public:
    Coordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getDistance(const Coordinates &coords) const {
        return sqrt(pow(this->y - coords.y, 2) + pow(this->x - coords.x, 2));
    }

    double getX() const{
    	return x;
    }

    double getY() const{
        return y;
     }

    bool operator==(const Coordinates &c){
    	return(this->x == c.getX() && this->y == c.getY());
    }
};


#endif
