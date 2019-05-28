#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

class Coordinates {

private:

    /**
     * @brief x coordinate
     * 
     */
    double x;

    /**
     * @brief y coordinate
     * 
     */
    double y;

public:

    /**
     * @brief Construct a new Coordinates object
     * 
     */
    Coordinates();

    /**
     * @brief Construct a new Coordinates object
     * 
     * @param x x coordinate
     * @param y y coordinate
     */
    Coordinates(double x, double y);

    /**
     * @brief gets the x coordinate
     * 
     * @return double x coordinate
     */
    double getX() const;

    /**
     * @brief gets the y coordinate
     * 
     * @return double y coordinate
     */
    double getY() const;

    /**
     * @brief Get the Distance object
     * 
     * @param coords coordinates to be calculated the distance
     * @return double distance
     */
    double getDistance(Coordinates coords) const;

    /**
     * @brief 
     * 
     * @param c coordinate that will be compared against
     * @return true coordinates are the same
     * @return false coordinates are not the same
     */
    bool operator==(const Coordinates &c);
};


#endif
