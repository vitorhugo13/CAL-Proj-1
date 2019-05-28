#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graph.h"
#include "Agenda.h"

class Application {

private:

    /**
     * @brief graph's application
     * 
     */
    Graph graph;

    /**
     * @brief agenda's application
     * 
     */
    Agenda agenda;
    
    /**
     * @brief load's information from txt files to graphs
     * 
     * @return int 
     */
    int loadGraph();

    /**
     * @brief load's information from txt files to user's agenda
     * 
     * @return int 
     */
    int loadAgenda();

    /**
     * @brief handles menu's input
     * 
     * @param nOptions option's number
     * @return int 
     */
    int menuInput(int nOptions);

    /**
     * @brief function that allows the user to choose a day to see its agenda
     * 
     * @return Day day to be seen
     */
    Day seeAgenda();

    /**
     * @brief shows the map of Porto's city
     * 
     * @return int 
     */
    int viewMap();



public:

    /**
     * @brief Construct a new Application object
     * 
     */
    Application();

    /**
     * @brief start's application
     * 
     * @return int 
     */
    int start();

};

#endif
