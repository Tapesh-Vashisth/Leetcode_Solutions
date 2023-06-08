#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const long long mod = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector <vector <pair <long long, long long>>> graph(n);
    for (auto it: roads) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }

    vector <pair <long long, long long>> dists(n, {INT64_MAX, INT64_MAX});
    dists[0] = {0, 1};
    set <pair <pair <long long, long long>, long long>> gp;
    gp.insert({{0, 1}, 0});

    while (!gp.empty()) {
        auto it = gp.begin();
        pair <pair <long long, long long>, long long> hold = (*it);
        gp.erase(it);


        for (long long i = 0; i < graph[hold.second].size(); i++) {
            long long cost = hold.first.first + graph[hold.second][i].second;

            if (cost < dists[graph[hold.second][i].first].first) {
                gp.insert({{cost, hold.first.second}, graph[hold.second][i].first});
                gp.erase({{dists[graph[hold.second][i].first].first, dists[graph[hold.second][i].first].second}, graph[hold.second][i].first});         
                dists[graph[hold.second][i].first] = {cost, hold.first.second};                
            } else if (cost == dists[graph[hold.second][i].first].first) {
                gp.insert({{cost, ((dists[graph[hold.second][i].first].second % mod) + (hold.first.second % mod)) % mod}, graph[hold.second][i].first});
                gp.erase({{dists[graph[hold.second][i].first].first, dists[graph[hold.second][i].first].second}, graph[hold.second][i].first});          
                dists[graph[hold.second][i].first] = {cost, ((dists[graph[hold.second][i].first].second % mod) + (hold.first.second % mod)) % mod};                
            }
        }
    }

    return dists[n - 1].second;
}const long long mod = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector <vector <pair <long long, long long>>> graph(n);
    for (auto it: roads) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }

    vector <pair <long long, long long>> dists(n, {INT64_MAX, INT64_MAX});
    dists[0] = {0, 1};
    set <pair <pair <long long, long long>, long long>> gp;
    gp.insert({{0, 1}, 0});

    while (!gp.empty()) {
        auto it = gp.begin();
        pair <pair <long long, long long>, long long> hold = (*it);
        gp.erase(it);


        for (long long i = 0; i < graph[hold.second].size(); i++) {
            long long cost = hold.first.first + graph[hold.second][i].second;

            if (cost < dists[graph[hold.second][i].first].first) {
                gp.insert({{cost, hold.first.second}, graph[hold.second][i].first});
                gp.erase({{dists[graph[hold.second][i].first].first, dists[graph[hold.second][i].first].second}, graph[hold.second][i].first});         
                dists[graph[hold.second][i].first] = {cost, hold.first.second};                
            } else if (cost == dists[graph[hold.second][i].first].first) {
                gp.insert({{cost, ((dists[graph[hold.second][i].first].second % mod) + (hold.first.second % mod)) % mod}, graph[hold.second][i].first});
                gp.erase({{dists[graph[hold.second][i].first].first, dists[graph[hold.second][i].first].second}, graph[hold.second][i].first});          
                dists[graph[hold.second][i].first] = {cost, ((dists[graph[hold.second][i].first].second % mod) + (hold.first.second % mod)) % mod};                
            }
        }
    }

    return dists[n - 1].second;
}

int main() {
    return 0;
}