#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graph.h"
#include "Agenda.h"

class Application {

private:
    Graph graph;
    Agenda agenda;

    int loadGraph();

public:

    Application() {
        graph = Graph();
        agenda = Agenda();
    }

    int startApplication();




};

#endif
