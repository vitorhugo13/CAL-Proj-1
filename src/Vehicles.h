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
    SubwayStation(std::string stationName, std::vector<char> lines) {
        this->stationName = stationName;
        this->lines = lines;
    }

    SubwayStation() {
        this->stationName = "";
        this->lines = {};
    }

    std::vector<char> getLines() {
        return lines;
    }

    bool findLine(const char line) {
        for (size_t i = 0; i < lines.size(); i++) {
            if (line == lines[i]) {
                return true;
            }
        }
        return false;
    }
};

#endif
