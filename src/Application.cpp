#include "Application.h"
#include "GraphViewer/graphviewer.h"

#include <iomanip>


Application:: Application() {
    graph = Graph();
    agenda = Agenda();
}


int Application::loadGraph() {
	std::cout << "Starting loading" << std::endl;

    if (graph.loadVertexes("data/nodes.txt")){
		return 1;
	}
	std::cout << "Loaded vertexes" << std::endl;
    
	
	if (graph.loadBusStops("data/bus.txt")) {
		return 2;
	}
	std::cout << "Loaded bus stops" << std::endl;

    if (graph.loadSubwayStations("data/subway.txt")) {
		return 3;
	}
	std::cout << "Loaded subway stations" << std::endl;
	

    if (graph.loadEdges("data/edges.txt")) {
		return 4;
	}
	std::cout << "Loaded edges" << std::endl;


	/*
	for (size_t i = 0; i < graph.getNumVertex(); i++) {
        std::cout << std::setprecision(16) << graph.getVertex(i)->getX() << ", " << graph.getVertex(i)->getY() << std::endl;
	}
	*/
	

    return 0;
}

int Application::loadAgenda() {

    agenda.loadActivities();

    return 0;
}

Day Application::seeAgenda(){
	std::string day;
	std::cout << "In which day? (dd-mm-yyyy)"<< std::endl;
	std::cin >> day;
	Day day1(day);
	return day1;
}

int Application::menuInput(int nOptions){
	int menu;
	std::cin >> menu;
	if (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Only integral numbers." << std::endl;
		return -2;
	}

	if (menu > nOptions || menu < -1){
		std::cout << "Option not valid! Try again." << std::endl;
		return -2;
	}
	return menu;
}

int Application::start() {

    if (loadGraph()) {
		return 1;
	}

    loadAgenda();

    int menu = -2;
	while(menu != 4){

		while(menu == -2){

			std::cout << "----- TripMate ----" << std::endl<< std::endl;
			std::cout << "1 - See Agenda" << std::endl;
			std::cout << "2 - Add activity" << std::endl;
			std::cout << "3 - Remove activity" << std:: endl;
			std::cout << "4 - See paths" << std::endl;
			std::cout << "5 - See Map" << std::endl;
			std::cout << "0 - Exit " << std::endl;

			std::cout << "Option: ";
			menu = menuInput(5);
			
			
		

			if(menu == -1)
				std::cout << "Menu does not exist" << std::endl;

			switch (menu){
					case 1:{
						agenda.show(seeAgenda());
						menu = -2;
						break;
						}
						
					case 2:{
						if(agenda.addActivity()){
							std::cout<< "Activity added with success!"<< std::endl;
							agenda.saveActivities();
						}
						else{
							std::cout<< "Activity can not be added!"<< std::endl;
						}			
						menu = -2;
						break;
					}

					case 3:{
						std::string name, date;
						std::cout << "Activity's name ?" << std::endl;
						std::cin.ignore();
						getline(std::cin,name);
						std::cout << "In which day? " << std::endl;
						std::cin >> date;
						Day day(date);
						if(agenda.removeActivity(name, date)){
							std::cout << "Activity removed with success! " << std::endl;
							agenda.saveActivities();
						}
						else
							std::cout << "Activity can not be removed!" << std::endl;
						menu = -2;
						break;
					}

					case 4:{
						agenda.show(seeAgenda());
						std::cout << "From which activity we want to see the path to the next activity ? " << std::endl;
						menu = -2;
						break;
					}

					case 5:
						viewMap();
						menu = -2;
						break;

					case 0:
						return 0;
						
					default:
						return 0;
				}
		}
	}
    
	return 0;
}

int Application::viewMap() {

	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	
	double minX = graph.getVertex(0)->getX();
	double minY = graph.getVertex(0)->getY();
	
	for (size_t i = 0; i < graph.getNumVertex(); i++) {
		if (graph.getVertex(i)->getX() < minX) {
			minX = graph.getVertex(i)->getX();
		}
		if (graph.getVertex(i)->getY() < minY) {
			minY = graph.getVertex(i)->getY();
		}
	}


	for (size_t i = 0; i < graph.getNumVertex(); i++) {
		gv->addNode(graph.getVertex(i)->getID(), graph.getVertex(i)->getX() - minX, graph.getVertex(i)->getY() - minY);
	}
	gv->rearrange();


	size_t edgeID = 0;
	for (size_t i = 0; i < graph.getNumVertex(); i++) {		
		for (size_t j = 0; j < graph.getVertex(i)->getNumEdges(); j++) {
			
			gv->addEdge(edgeID, graph.getVertex(i)->getID(), graph.getVertex(i)->getEdge(j)->getDest()->getID(), EdgeType::DIRECTED);
			edgeID++;
			
			//std::cout << graph.getVertex(i)->getID() << " , " << graph.getVertex(i)->getEdge(j)->getDest()->getID() << std::endl;
		}
		
	}
	gv->rearrange();

	std::cout << std::endl << "Press ENTER to close the map" << std::endl;
	std::cin.ignore();
	std::cin.get();
	gv->closeWindow();

	return 0;
}