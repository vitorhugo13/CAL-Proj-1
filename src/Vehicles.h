#ifndef VEHICLES_H
#define VEHICLES_H

#include <string>
#include <vector>

/*
class BusStop {

private:
    std::string stopID;
    std::string lineID;
    std::string zoneID;
    std::string council;
    std::string parish;
    std::string address;
    std::string type;

public:
    BusStop(std::string stopID, std::string lineID, std::string zoneID, std::string council, std::string parish, std::string address, std::string type) {
        this->stopID = stopID;
        this->lineID = lineID;
        this->zoneID = zoneID;
        this->council = council;
        this->parish = parish;
        this->address = address;
        this->type = type;
    }

    BusStop() {
        this->stopID = "";
        this->lineID = "";
        this->zoneID = "";
        this->council = "";
        this->parish = "";
        this->address = "";
        this->type = "";
    }
};
*/

class SubwayStation {

private:
    std::string stationName;
    std::vector<char> lines;

public:
    SubwayStation();
    SubwayStation(std::string stationName, std::vector<char> lines);

    std::string getName();

    std::vector<char> getLines();

    bool findLine(const char line);
};

#endif
