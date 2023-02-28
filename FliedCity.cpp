// Berk Sara
// 22102354
// Section 02

#include "FliedCity.h"
#include <string>
#include <iostream>
FliedCity::FliedCity(string departure, string arrival, bool visited, int ID, int cost) {
    this->departure = departure;
    this->arrival = arrival;
    this->visited = visited;
    this->ID = ID;
    this->cost = cost;
}

bool FliedCity::isItVisited() {
    return visited;
}

int FliedCity::getID() {
    return ID;
}

int FliedCity::getCost() {
    return cost;
}

void FliedCity::setVisited(bool visited) {
    this->visited = visited;
}

void FliedCity::setCost(int cost) {
    this->cost = cost;
}

void FliedCity::setID(int id) {
    this->ID = id;
}

string FliedCity::getDeparture() {
    return departure;
}

string FliedCity::getArrival() {
    return arrival;
}

void FliedCity::setDeparture(string name) {
    this->departure = name;
}

void FliedCity::setArrival(string name) {
    this->arrival = name;
}

FliedCity::~FliedCity() {

}
