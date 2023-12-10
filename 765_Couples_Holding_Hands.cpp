#include <iostream>
#include <vector>
using namespace std;

int minSwapsCouples(vector<int>& row) { 
    vector <int> graph(row.size(), -1);
    for (int i = 0; i < row.size(); i += 2) {
        graph[row[i]] = row[i + 1];
        graph[row[i + 1]] = row[i];
    }        

    int ans = 0;

    vector <bool> hashed(row.size(), false);

    for (int i = 0; i < graph.size(); i++) {
        if (hashed[i] == false) {
            if (graph[i] == i + 1) {
                ;
            } else {
                ans++;
                graph[graph[i]] = graph[i + 1];
                graph[graph[i + 1]] = graph[i];
                graph[i] = i + 1;
            }

            hashed[i] = true;
            hashed[graph[i]] = true;
        }
    }

    return ans;
}

int main() {
    return 0;
}