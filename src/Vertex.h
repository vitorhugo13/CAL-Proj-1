#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "Edge.h"



#define INF std::numeric_limits<int>::max()


template <class T>
class Vertex {
    
private:
    static unsigned int id;
    std::string info;
    std::vector<Edge<T>> paths;
    unsigned int x, y;
    int cost = INF;

public:


};


#endif
