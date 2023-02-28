// Berk Sara
// 22102354
// Section 02


#ifndef CS_HW4_FLIGHTMAP_H
#define CS_HW4_FLIGHTMAP_H
#include "string"
#include <map>
#include <algorithm>
#include "FliedCity.h"
#include "vector"
#include "stack"
using namespace std;

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    bool checkFile(const string fileName);
    stack<FliedCity*> findingFlights(const string deptCity, const string destCity) const;
    void markCity(string cityName) const;
    void unMarkCity(string cityName) const;
    static bool compareFunction (FliedCity* a, FliedCity* b);
private:
    map<string, vector<FliedCity*>* > flightMap;
};


#endif //CS_HW4_FLIGHTMAP_H
