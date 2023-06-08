#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    map <pair <string, string>, pair <double, int>> store;
    unordered_map <int, pair <string, int>> checkins;

    UndergroundSystem() {
        ;
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        store[{checkins[id].first, stationName}] = {store[{checkins[id].first, stationName}].first + (t - checkins[id].second), store[{checkins[id].first, stationName}].second + 1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return store[{startStation, endStation}].first/store[{startStation, endStation}].second;
    }
};

int main() {
    return 0;
}