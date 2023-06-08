#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;




class graph{
    list <int> * l;
    int v;
    
    public: 
        graph(int V){
            v = V;
            l = new list<int>[v];
        }

        void addEdge(int i, int j, bool undir = true){
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
                cout << root << " ";
                for (auto hold: this->l[root]){
                    dfsHelper(hold, visited);
                }
            }
        }

        void dfs(int source){
            vector <bool> visited(this->v, false);
            dfsHelper(source, visited);
            cout << endl;
        }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    graph g(n);
    for (int i = 0; i < flights.size(); i++) {
    
    }       
}

int main() {
    return 0;
}