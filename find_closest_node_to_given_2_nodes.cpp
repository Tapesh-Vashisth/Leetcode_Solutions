#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class graph{
    list <int> * l;
    int v;
    
    public: 
        vector <int> dfsvec;

        graph(int V){
            v = V;
            l = new list<int>[v];
        }

        void addEdge(int i, int j, bool undir = false){
            l[i].push_back(j);
            if (undir){
                l[j].push_back(i);
            }
        }

        void print(){
            for (int i = 0; i < this->v; i++){
                cout << i << "--->";
                for (auto hold: l[i]){
                    cout << hold << ' ';
                }
                cout << endl;
            }
        }

        void bfs(int source){
            queue <int> q;
            vector <bool> visited(this->v, false);

            q.push(source);
            visited[source] = true;

            while (!q.empty()){
                int hold = q.front();
                q.pop();

                cout << hold << " ";
                for (auto move: l[hold]){
                    if (visited[move] != true){
                        q.push(move);
                        visited[move] = true;
                    }
                }
            }
            
            cout << endl;
        }

        void dfsHelper(int root, vector <bool>& visited){
            if (visited[root] == false){
                visited[root] = true;
                dfsvec.push_back(root);
                for (auto hold: this->l[root]){
                    dfsHelper(hold, visited);
                }
            }
        }

        vector <int> dfs(int source){
            dfsvec.clear();
            vector <bool> visited(this->v, false);
            dfsHelper(source, visited);
            return dfsvec;
        }
};

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    graph g(edges.size());

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i] != -1) {
            g.addEdge(i, edges[i]);
        }
    }

    g.print();
    vector <int> firstnode = g.dfs(node1);
    vector <int> secondnode = g.dfs(node2);

    for (int i = 0; i < firstnode.size(); i++) {
        cout << firstnode[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < secondnode.size(); i++) {
        cout << secondnode[i] << " ";
    }
    cout << endl;

    vector <int> mapped(edges.size(), -1);

    for (int i = 0; i < firstnode.size(); i++) {
        mapped[firstnode[i]] = i;
    }

    pair <int, int> ans = {-1, INT32_MAX};

    for (int i = 0; i < secondnode.size(); i++) {
        if (mapped[secondnode[i]] != -1) {
            int hold = max(mapped[secondnode[i]], i);
            if (hold < ans.second) {
                ans.first = secondnode[i];
                ans.second = hold;
            }
        }
    }
    
    return ans.first;
}

int main() {
    vector <int> edges = {1,2,-1};
    cout << closestMeetingNode(edges, 0, 2) << endl;

    return 0;
}