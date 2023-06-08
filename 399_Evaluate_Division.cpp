#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

double helper(unordered_map <string, vector <pair <string, double>>> & mapping, string & current, string & destination, unordered_map <string, int> & visited) {
    if (visited[current] == 0) {
        visited[current] = 1;
        if (current == destination) {
            return 1;
        }

        double ret = -1;
        for (int i = 0; i < mapping[current].size(); i++) {
            double hold = helper(mapping, mapping[current][i].first, destination, visited);
            if (hold != -1) {
                ret = hold * mapping[current][i].second;
            }
        }

        return ret;
    } else {
        return -1;
    }
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map <string, vector <pair <string, double>>> mapping;

    for (int i = 0; i < equations.size(); i++) {
        mapping[equations[i][0]].push_back({equations[i][1], values[i]});
        mapping[equations[i][1]].push_back({equations[i][0], 1/values[i]});
    }

    vector <double> ans;
    for (int i = 0; i < queries.size(); i++) {
        unordered_map <string, int> visited;
        if (mapping[queries[i][0]].size() == 0 || mapping[queries[i][1]].size() == 0) {
            ans.push_back(-1);
        } else {
            double hold = helper(mapping, queries[i][0], queries[i][1], visited);
            ans.push_back(hold);
        }
    }

    return ans;
}

int main() {
    return 0;
}