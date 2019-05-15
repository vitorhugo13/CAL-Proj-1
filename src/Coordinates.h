#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {

private:
    long int x, y;

public:
    Coordinates(long int x, long int y) {
        this->x = x;
        this->y = y;
    }

    double getDistance(const Coordinates &coords) const;

    long int getX() const{
    	return x;
    }

    long int getY() const{
        return y;
     }

    bool operator==(const Coordinates &c){
    	return(this->x == c.getX() && this->y == c.getY());
    }
};


#endif
