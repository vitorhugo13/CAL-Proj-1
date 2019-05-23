#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graph.h"
#include "Agenda.h"

class Application {

private:
    Graph graph;
    Agenda agenda;
    
    int loadGraph();
    int loadAgenda();

    int menuInput(int nOptions);
    Day seeAgenda();

    int viewMap();



public:

    Application();

    int start();

};

#endif
