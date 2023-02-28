#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include "fstream"
#include "FliedCity.h"
#include "FlightMap.h"
using namespace std;

bool compareFunction (std::string a, std::string b) {return a<b;}

int main() {
/*
    // Vector example
    vector< int > myVector;
    myVector.push_back( 10 );
    myVector.push_back( 20 );
    myVector.push_back( 30 );
    myVector[ 1 ] = -50;
    myVector[ 3 ] = 40;

    vector<string> vect;
    vect.push_back("aa");
    vect.push_back("cc");
    vect.push_back("bb");
    for( int i = 0; i < vect.size(); i++ )
        cout << " " << vect[ i ];
    cout << endl;
    for (auto x : vect)
        cout << x << " ";
    std::sort(vect.begin(), vect.end(), compareFunction);

    cout << "Size of vector: " << myVector.size() << endl;
    cout << "First element: " << myVector.front() << endl;
    cout << "Last element: " << myVector.back() << endl;
    cout << "Contents of the vector:";
    for ( int i = 0; i < myVector.size(); i++ )
        cout << " " << myVector[ i ];
    cout << endl;
    cout << "Alternative way:";
    vector< int >::iterator vecIterator;
    for ( vecIterator = myVector.begin(); vecIterator != myVector.end(); vecIterator++ )
        cout << " " << *vecIterator;
    cout << endl;

    cout << endl;

    // List example
    list< int > myList;
    myList.push_front( 1 );
    myList.push_front( 2 );
    myList.push_back( 3 );
    cout << "Contents of the list:";
    for ( int& i : myList )
        cout << " " << i;
    cout << endl;

    list< int >::iterator listIterator;
    listIterator = myList.begin();
    listIterator++;
    myList.insert( listIterator, 111 );
    listIterator++;
    myList.insert( listIterator, 222 );
    listIterator--;
    myList.insert( listIterator, 333 );
    cout << "Contents of the list:";
    for ( int& i : myList )
        cout << " " << i;
    cout << endl;
    myList.push_front( 15 );
    myList.push_front( 38 );
    cout << "Contents of the list:";
    for ( int& i : myList )
        cout << " " << i;
    cout << endl;
    myList.pop_front();
    myList.pop_back();
    cout << "Contents of the list:";
    for ( int& i : myList )
        cout << " " << i;
    cout << endl;
    myList.sort();
    cout << "Contents of the list:";
    for ( int& i : myList )
        cout << " " << i;
    cout << endl;
    cout << "Contents of the list:";
    list< int >::reverse_iterator listRevIterator;
    for ( listRevIterator = myList.rbegin(); listRevIterator != myList.rend(); listRevIterator++ )
        cout << " " << *listRevIterator;
    cout << endl;

    cout << endl;

    // Stack example
    stack< int > myStack;
    myStack.push( 1 );
    myStack.push( 2 );
    myStack.push( 3 );
    myStack.push( 4 );

    cout << "Contents of the stack:";
    while ( !myStack.empty() ) {
        cout << " " << myStack.top();
        myStack.pop();
    }
    cout << endl;

    cout << endl;

    // Queue example
    queue< int > myQueue;
    myQueue.push( 1 );
    myQueue.push( 2 );
    myQueue.push( 3 );
    myQueue.push( 4 );

    cout << "Contents of the queue:";
    while ( !myQueue.empty() ) {
        cout << " " << myQueue.front();
        myQueue.pop();
    }
    cout << endl;

    cout << endl;

    // Set example
    set< int > mySet;
    mySet.insert( 1 );
    mySet.insert( 100 );
    mySet.insert( 10 );
    mySet.insert( 199 );
    mySet.insert( 5 );

    cout << "Contents of the set:";
    for ( const int& s : mySet )
        cout << " " << s;
    cout << endl;
    cout << "Does the set contain 10? " << mySet.count( 10 ) << endl;
    cout << "Does the set contain 1000? " << mySet.count( 1000 ) << endl;

    cout << endl;

    // Map example
    map< string, int > cityMap;
    cityMap[ "Ankara" ] = 6;
    cityMap[ "Istanbul" ] = 34;
    cityMap[ "Izmir" ] = 35;
    cityMap.insert( pair< string, int >( "Adana", 1 ) );
    cityMap.insert( { "Zonguldak", 67 } );

    cout << "Contents of the map:" << endl;
    map< string, int >::iterator mapIterator;
    for ( mapIterator = cityMap.begin(); mapIterator != cityMap.end(); mapIterator++ )
        cout << mapIterator->first << ": " << mapIterator->second << endl;
    cout << "Alternative way:" << endl;
    for ( const auto& [key, value] : cityMap )
        cout << key << ": " << value << endl;
    cout << "Does the map contain Ankara? " << cityMap.count( "Ankara" ) << endl;
    cout << "Does the map contain Eskisehir? " << cityMap.count( "Eskisehir" ) << endl;
    cout << "What is the number for Ankara? ";
    mapIterator = cityMap.find( "Ankara" );
    if ( mapIterator != cityMap.end() )
        cout << mapIterator->second << endl;
    else
        cout << "Not found" << endl;
    cout << "What is the number for Bursa? ";
    mapIterator = cityMap.find( "Bursa" );
    if ( mapIterator != cityMap.end() )
        cout << mapIterator->second << endl;
    else
        cout << "Not found" << endl;


    cout << endl;
    cout << endl;
    cout << endl;

    string flightTxt = "C:\\Users\\PC\\Desktop\\flight.txt";
    ifstream inputFile;
    inputFile.open( flightTxt.c_str(), ios_base::in);
    string str;
    inputFile >> str;
    cout << str << endl;
    inputFile.close();

*/
/*
    FlightMap fmap("city.txt", "flight.txt");
    fmap.displayAllCities();
    fmap.displayAdjacentCities("W");
    fmap.displayFlightMap();
    fmap.findFlights("P", "Z");
        cout << endl;

   */
/*
    FlightMap fm( "city.txt", "flight.txt" );
    fm.displayAllCities();
    cout << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;
    fm.displayAdjacentCities( "X" );
    cout << endl;
    fm.displayFlightMap();
    cout << endl;

    fm.findFlights( "W", "Z" );
    cout << endl;

    fm.findFlights( "S", "P" );
    cout << endl;

    fm.findFlights( "Y", "Z" );
    cout << endl;

    fm.findFlights( "P", "Z" );
    cout << endl;
*/
    FlightMap fm( "", "" );
    fm.displayAllCities();
    cout << endl;

    fm.displayAdjacentCities( "X" );
    cout << endl;

    fm.displayAdjacentCities( "W" );
    cout << endl;

    fm.displayFlightMap();
    cout << endl;


    fm.findFlights("W", "X");
    fm.findFlights("S", "X");

    return 0;
}
