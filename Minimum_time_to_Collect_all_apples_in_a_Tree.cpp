#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class graph{
    list <int> * l;
    int v;
    
    public: 
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

        int minCostHelper(int root, vector <bool>& visited, vector <bool> & hasApples){
            if (visited[root] == false){
                visited[root] = true;
                if (this->l[root].size() == 0){
                    return 0;
                }

                cout << root << " ";
                int total = 0;
                for (auto hold: this->l[root]){
                    total += minCostHelper(hold, visited, hasApples);
                }

                if (hasApples[root]) {
                    return total + 2;
                } else {
                    return total;
                }
            } else {
                return 0;
            }
        }

        int minCost(int source, vector <bool> & hasApples){
            vector <bool> visited(this->v, false);
            int ans = minCostHelper(source, visited, hasApples);
            cout << endl;
            return ans;
        }
};

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    graph g(n);
    for (int i = 0; i < edges.size(); i++) {    
        g.addEdge(edges[i][0], edges[i][1]);
    }

    g.print();

    return g.minCost(0, hasApple);
}

int main(){
    return 0;
}