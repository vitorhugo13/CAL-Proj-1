#include "Vehicles.h"



SubwayStation::SubwayStation(std::string stationName, std::vector<char> lines) {
    this->stationName = stationName;
    this->lines = lines;
}

SubwayStation::SubwayStation() {
    this->stationName = "";
    this->lines = {};
}

std::vector<char> SubwayStation::getLines() {
    return lines;
}

bool SubwayStation::findLine(const char line) {
    for (size_t i = 0; i < lines.size(); i++) {
        if (line == lines[i]) {
            return true;
        }
    }
    return false;
}