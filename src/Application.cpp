#include "Application.h"
#include "GraphViewer/graphviewer.h"

#include <iomanip>
#include <chrono>

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

	// load walking edges
    if (graph.loadEdges("data/edges.txt", WALKING)) {
		return 1;
	}
	std::cout << "Loaded walking edges" << std::endl;

	// load bus edges
    if (graph.loadEdges("data/edges_bus.txt", BUS)) {
		return 1;
	}
	std::cout << "Loaded bus edges" << std::endl;

	// load subway edges
    if (graph.loadEdges("data/edges_subway.txt", WALKING)) {
		return 1;
	}
	std::cout << "Loaded subway edges" << std::endl;

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
						std::string date;

						std::cout << "What day you want to see the path ? " << std::endl;
						std::cin.ignore();
						getline(std::cin,date);

						Day day(date);
						//coord is a vector with the coordinates of all place in that day

						std::vector<Coordinates> coord = agenda.getCoords(day);

						if (coord.size()> 1) {

							std::vector< Vertex*> vertexs;
							std::vector<Time> travelTimes;

							for (Coordinates coordinates : coord) {
								Vertex* newVertex = graph.findNearestVertex(coordinates);
								std::cout << newVertex->getID() << std::endl;										
								vertexs.push_back(newVertex);
							}

							for(size_t i = 0; i < vertexs.size() - 1; i++) {		
								
								auto begin = std::chrono::high_resolution_clock::now();	
								graph.dijsktraAlgorithm(vertexs[i], vertexs[i + 1]);
								auto end = std::chrono::high_resolution_clock::now();  
    							std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()  << "ns" << std::endl;
								
								Time travelTime;
								stack<Vertex*> path = graph.getPath(vertexs[i + 1]);
								std::string directions = graph.getDirections(path, travelTime);
								travelTimes.push_back(travelTime);

								std::cout << directions << std::endl;
								std::cout << travelTime << std::endl;
							}
							/* table that shows if we going to be on time to the next event */
							agenda.show(agenda.onTime(travelTimes, day),day);		

						} 
						else{

							std::cout << std::endl << " No paths to see!" << std::endl << std::endl ;
						}					
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

	int width = 600;
	int height = 600;

	GraphViewer *gv = new GraphViewer(width, height, false);
	gv->createWindow(width, height);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	
	double minX = graph.getVertex(0)->getX();
	double minY = graph.getVertex(0)->getY();
	double maxX = graph.getVertex(0)->getX();
	double maxY = graph.getVertex(0)->getY();
	
	for (size_t i = 0; i < graph.getNumVertex(); i++) {
		if (graph.getVertex(i)->getX() < minX) {
			minX = graph.getVertex(i)->getX();
		}
		else if (graph.getVertex(i)->getX() > maxX) {
			maxX = graph.getVertex(i)->getX();
		}

		if (graph.getVertex(i)->getY() < minY) {
			minY = graph.getVertex(i)->getY();
		}
		else if (graph.getVertex(i)->getY() > maxY) {
			maxY = graph.getVertex(i)->getY();			
		}
	}

	double medX = (maxX - minX) / 2;
	double medY = (maxY - minY) / 2;

	for (size_t i = 0; i < graph.getNumVertex(); i++) {
		gv->addNode(graph.getVertex(i)->getID(), graph.getVertex(i)->getX() - minX - medX + width / 2, -graph.getVertex(i)->getY() + minY + medY + height / 2);
	}
	gv->rearrange();


	size_t edgeID = 0;
	for (size_t i = 0; i < graph.getNumVertex(); i++) {		
		for (size_t j = 0; j < graph.getVertex(i)->getNumEdges(); j++) {
			
			switch (graph.getVertex(i)->getEdge(j)->getEdgeType()) {
				case WALKING:
					gv->setEdgeColor(edgeID, "black");
					break;
				case BUS:
					gv->setEdgeColor(edgeID, "red");
					break;
				case SUBWAY:
					gv->setEdgeColor(edgeID, "green");
					break;
				default:
					break;
			}

			gv->addEdge(edgeID, graph.getVertex(i)->getID(), graph.getVertex(i)->getEdge(j)->getDest()->getID(), EdgeType::DIRECTED);
			edgeID++;
		}	
	}
	gv->rearrange();

	std::cout << std::endl << "Press ENTER to close the map" << std::endl;
	std::cin.ignore();
	std::cin.get();
	gv->closeWindow();

	return 0;
}
