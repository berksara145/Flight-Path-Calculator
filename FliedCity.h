// Berk Sara
// 22102354
// Section 02

#ifndef CS_HW4_CITY_H
#define CS_HW4_CITY_H
#include <string>
using namespace std;

class FliedCity {
public:
    FliedCity(string, string, bool, int, int);
    ~FliedCity();
    string getDeparture();
    string getArrival();
    bool isItVisited();
    int getID();
    int getCost();
    void setDeparture(string name);
    void setArrival(string name);
    void setVisited(bool visited);
    void setCost(int cost);
    void setID(int id);
private:
    string arrival;
    string departure;
    bool visited;
    int ID;
    int cost;
};


#endif //CS_HW4_CITY_H
