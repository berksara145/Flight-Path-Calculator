// Berk Sara
// 22102354
// Section 02

#include "FlightMap.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "fstream"
#include <vector>
#include <map>
#include "FliedCity.h"

using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile) {

    //for pc
    string cityTxt = "C:\\Users\\PC\\Desktop\\city.txt";
    string flightTxt = "C:\\Users\\PC\\Desktop\\flight.txt";

    //string cityTxt = cityFile;
    //string flightTxt = flightFile;

    int cityCount = 0;
    int flightCount = 0;
    string cityName;
    string details;
    string departure;
    string arrival;
    int id;
    int cost;
    int order = 1;
    ifstream inputFile;

    if( !(checkFile(cityTxt)) ){
        cout << "Input file " << cityTxt <<" does not exist" <<endl;
        return;
    }
    if( !(checkFile(flightTxt)) ){
        cout << "Input file " << flightTxt <<" does not exist" <<endl;
        return;
    }
    string sameName = "";
    inputFile.open( cityTxt.c_str(), ios_base::in );
    //Continue until the end of the file
    while ( inputFile.eof() == false ) {
        inputFile >> cityName;
        if(cityName != sameName){
            vector<FliedCity*>* vector = new std::vector<FliedCity*>();
            flightMap[cityName] = vector;
            cityCount++;
            vector = nullptr;
        }
        sameName = cityName;
    }
    //Close the input file stream
    inputFile.close();
    inputFile.open( flightTxt.c_str(), ios_base::in);
    while ( inputFile.eof() == false ) {
        inputFile >> details;
        if(sameName != details){
            int index1 = 0;
            for (int i = 0; i < details.size(); ++i) {
                string str;
                if(details[i] == ';'){
                    str = details.substr(index1, i - index1);
                    if(order == 1){
                        departure = str;
                        order++;
                        index1 = i + 1;
                    }
                    else if(order == 2){
                        arrival = str;
                        order++;
                        index1 = i + 1;
                    }
                    else if(order == 3){
                        id = std::stoi(str);
                        order++;
                        index1 = i + 1;
                    }
                }
                if(i == details.size() - 1){
                    str = details.substr(index1, i + 1 - index1);
                    cost = std::stoi(str);
                    order = 1;
                }
            }
            FliedCity* city = new FliedCity(departure,arrival,false,id,cost);
            map< string, vector<FliedCity*>* >::iterator ite;
            ite = flightMap.find(departure);
            vector<FliedCity*>* cities =  ite->second;
            cities->push_back(city);
            flightCount++;
        }
        sameName = details;
    }
    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        string cityName2 = mapIterator->first;
        vector<FliedCity*>* vect = flightMap.find(cityName2)->second;
        std::sort(vect->begin(), vect->end(), compareFunction);
    }
    cout << cityCount << " cities and "<< flightCount <<" flights have been loaded";
    cout << endl;
    inputFile.close();
}
bool FlightMap::compareFunction(FliedCity* a, FliedCity* b) {
    {return a->getArrival() < b->getArrival();}
}

FlightMap::~FlightMap() {

    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        string cityName = mapIterator->first;
        vector<FliedCity*> vector = *(flightMap.find(cityName)->second);
        for ( int i = 0; i < vector.size(); i++ ){
            delete vector[ i ];
        }
        delete mapIterator->second ;
    }
    flightMap.clear();
}

void FlightMap::displayAllCities() const {
    cout << "The list of the cities that HPAir serves is given below:" << endl;

    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        cout << mapIterator->first << ", ";
    }
    cout << endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const {
    cout << "The cities adjacent to "<< cityName <<" are:" <<endl;
    vector<FliedCity*> vector = *(flightMap.find(cityName)->second);
    cout << cityName <<" -> ";
    for ( int i = 0; i < vector.size(); i++ ){
        cout << vector[ i ]->getArrival() << ", ";
    }
    cout << endl;
}

void FlightMap::displayFlightMap() const {
    cout << "The whole flight map is given below:" << endl;
    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        string cityName = mapIterator->first;
        vector<FliedCity*> vector = *(flightMap.find(cityName)->second);
        cout << cityName <<" -> ";
        for ( int i = 0; i < vector.size(); i++ ){
            cout << vector[ i ]->getArrival() << ", ";
        }
        cout << endl;
    }
}

void FlightMap::findFlights(const string deptCity, const string destCity) const {

    cout << "Request is to fly from "<< deptCity <<" to "<< destCity << ":" <<endl;


    string str = "";
    string strTotal = "";
    int count = 0;
    stack<FliedCity*> readingStack = findingFlights(deptCity, destCity);

    auto mapIter = flightMap.begin();
    for ( mapIter = flightMap.begin(); mapIter != flightMap.end(); mapIter++ ){
        string city = mapIter->first;
        vector<FliedCity*> vector = *(flightMap.find(city)->second);
        for ( int i = 0; i < vector.size(); i++ ){
            vector[i]->setVisited(false);
        }
    }

    map<int, string> displayMap;
    if(readingStack.empty()){
        cout << "Sorry. HPAir does not fly from "<< deptCity <<" to "<< destCity <<"." << endl;
    }
    while( !readingStack.empty()){
        FliedCity* temp = readingStack.top();
        str =  "Flight #"+ to_string(temp->getID()) +" from " + temp->getDeparture() +
               " to " + temp->getArrival() +", Cost: " + to_string(temp->getCost()) +" TL\n" + str;
        count += temp->getCost();
        readingStack.pop();

        if(temp->getDeparture() == deptCity ){
            strTotal += "Total Cost: " + to_string(count) + " TL\n" ;
            displayMap[ count ] = str + strTotal;
            //cout << str + strTotal ;
            count = 0;
            strTotal = "";
            str = "";
        }
        else{
            strTotal = "";
        }
    }
    auto mapIterator = displayMap.begin();
    for ( mapIterator = displayMap.begin(); mapIterator != displayMap.end(); mapIterator++ ){
         cout << mapIterator->second;
    }
}

bool FlightMap::checkFile(const string fileName) {
    ifstream f(fileName.c_str());
    return f.good();
}

stack<FliedCity*> FlightMap::findingFlights(const string deptCity, const string destCity) const {
    stack<FliedCity*> bigStack;
    stack<FliedCity*> pathStack;
    string departure = deptCity;

    //ptr that will be used to traverse the ADT and initializes the ptr
    vector<FliedCity*> vectorr = *flightMap.find(deptCity)->second;
    FliedCity* nextCity = nullptr;
    for ( int i = 0; i < vectorr.size(); i++ ){
        if( !vectorr[ i ]->isItVisited() ){
            nextCity = vectorr[i];
            string name = nextCity->getArrival();
            break;
        }
    }
    //marking the beginning
    markCity(deptCity);
    //traverses all the possible solutions with pointer
    //while condition is if there is no unmarked city left in the departure city's vector
    bool continuing = true;
    string leftOfCity = "";
    bool unmarking = false;
    while(nextCity != nullptr) {
        bool done = true;
        vector<FliedCity*> vector2 = *flightMap.find(departure)->second;
        for(int i = 0; i < vector2.size(); i++ ){
            if(leftOfCity == ""){ continuing = true;}
            if(vector2[ i ]->getArrival() == leftOfCity){ continuing = true;}
            if( !vector2[ i ]->isItVisited() && continuing){
                nextCity = vector2[ i ];
                string name = nextCity->getArrival();
                done = false;
                break;
            }
            if(vector2[ i ]->getArrival() == leftOfCity){
                if(unmarking){
                    unMarkCity(vector2[i]->getArrival());
                }
            }
        }
        continuing = false;
        if(pathStack.empty()){
            unmarking = false;
        }

        if(departure == destCity){
            if( !pathStack.empty()){
                stack<FliedCity*> temp;
                while( !pathStack.empty()){
                    temp.push( pathStack.top());
                    pathStack.pop();
                }
                while( !temp.empty()){
                    bigStack.push(temp.top());
                    pathStack.push(temp.top());
                    temp.pop();
                }
            }
            done = true;
            unmarking = true;
        }
        if(done){
            if(!pathStack.empty()){
                departure = pathStack.top()->getDeparture();
                leftOfCity = pathStack.top()->getArrival();
                pathStack.pop();
            }
            else{
                break;
            }
        }
        else{
            //if there is nextCity avaiable
            pathStack.push(nextCity);
            markCity(nextCity->getArrival());
            departure = nextCity->getArrival();
            leftOfCity = "";
        }
    }
    //returns the big stack
    return bigStack;
}

void FlightMap::markCity(string cityName) const {
    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        string city = mapIterator->first;
        vector<FliedCity*> vector = *(flightMap.find(city)->second);
        for ( int i = 0; i < vector.size(); i++ ){
            if(vector[i]->getArrival() == cityName){
                vector[i]->setVisited(true);
            }
        }
    }
}

void FlightMap::unMarkCity(string cityName) const {
    auto mapIterator = flightMap.begin();
    for ( mapIterator = flightMap.begin(); mapIterator != flightMap.end(); mapIterator++ ){
        string city = mapIterator->first;
        vector<FliedCity*> vector = *(flightMap.find(city)->second);
        for ( int i = 0; i < vector.size(); i++ ){
            if(vector[i]->getArrival() == cityName){
                vector[i]->setVisited(false);
            }
        }
    }
}


