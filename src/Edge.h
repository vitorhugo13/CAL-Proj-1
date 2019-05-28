#ifndef EDGE_H
#define EDGE_H


#include <vector>
#include <limits>

#include "Time.h"


class Vertex;

#define INT_INF     std::numeric_limits<int>::max()
#define DOUBLE_INF  std::numeric_limits<double>::max()


const double BUS_MULTIPLIER = 0.00003;
const double SUBWAY_MULTIPLIER = 0.00002;
const double WALKING_MULTIPLIER = 0.0002;


enum Type { WALKING, BUS, SUBWAY, UNDEFINED };


class Edge {

protected:

    Vertex *srcVertex, *destVertex;
    
    double distance;
    Time time;

    Type type;

public:

    /**
	 * @brief Construct a new Edge object
	 * 
	 * @param src  the source vertex
	 * @param dest the vertex of destiny
	 * @param type the type of transporter of the edge
	 */
    Edge(Vertex *src, Vertex *dest, Type type);

    /**
     * @brief Get a pointer to the source vertex of the edge
     * 
     * @return Vertex* Returns a pointer to the vertex
     */
    Vertex* getSrc() {
        return srcVertex;
    }

    /**
     * @brief Get the Dest object
     * 
     * @return Vertex* 
     */
    Vertex* getDest() {
        return destVertex;
    }    

    /**
     * @brief Get the Distance object
     * 
     * @return double 
     */
    double getDistance();
    /**
     * @brief Get the Time object
     * 
     * @return Time 
     */
    Time getTime();

    /**
     * @brief Get the Edge Type object
     * 
     * @return Type
     */
    Type getEdgeType();

    friend class Graph;
    friend class Vertex;
};





#endif
