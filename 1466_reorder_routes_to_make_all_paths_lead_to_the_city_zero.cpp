#include <iostream>
#include <vector>
using namespace std;

void counter(int root, vector <bool> & visited, vector <vector <int>>& child, vector <vector <int>>& parents, int & ans) {
    if (visited[root] == false) {
        visited[root] = true;
        // child 
        for (auto it: child[root]) {
            if (visited[it] == false) {
                ans++;
                counter(it, visited, child, parents, ans);
            }
        }

        // parent 
        for (auto it: parents[root]) {
            if (visited[it] == false) {
                counter(it, visited, child, parents, ans);
            }
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector <vector <int>> parents(n);
    vector <vector <int>> child(n);


    for (auto it: connections) {
        child[it[0]].push_back(it[1]);
        parents[it[1]].push_back(it[0]);
    }

    for (auto it: child[0]) {
        cout << it << " ";
    }
    cout << endl;

    for (auto it: parents[0]) {
        cout << it << " ";
    }
    cout << endl;

    vector <bool> visited(n, false);
    int ans = 0;

    counter(0, visited, child, parents, ans);

    return ans;
}

int main() {
    return 0;
}