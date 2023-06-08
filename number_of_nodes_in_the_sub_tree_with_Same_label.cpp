#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;


class graph{
    list <int> * l;
    list <int> * p;
    int v;
    
    public: 
        graph(int V){
            v = V;
            l = new list<int>[v];
            p = new list<int>[v];
        }

        void addEdge(int i, int j, bool undir = true){
            p[j].push_back(i);
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

        void printParents(){
            for (int i = 0; i < this->v; i++){
                cout << i << "--->";
                for (auto hold: p[i]){
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

                for (auto move: l[hold]){
                    if (visited[move] != true){
                        q.push(move);
                        visited[move] = true;
                    }
                }
            }
            
            cout << endl;
        }

        void traverse(vector <int> & ans, int root, string labels, char search) {
            if (this->p[root].size() != 0) {
                if (labels[root] == search) {
                    ans[root]++;
                }

                for (auto i: this->p[root]) {
                    traverse(ans, i, labels, search);
                }
            }
        }

        void dfsHelper(int root, vector <bool>& visited, vector <int>& ans, string & labels){
            if (visited[root] == false){
                visited[root] = true;

                for (auto hold: this->l[root]){
                    dfsHelper(hold, visited, ans, labels);
                }

                // traverse up the tree 
                traverse(ans, root, labels, labels[root]);
            }
        }

        vector <int> dfs(int source, int len, string & labels){
            vector <int> ans(len, 0);
            vector <bool> visited(this->v, false);
            dfsHelper(source, visited, ans, labels);

            return ans;
        }
};

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    graph g(n);
    vector <int> ans;
    for (int i = 0; i < edges.size(); i++) {
        g.addEdge(edges[i][0], edges[i][1]);
    }
    cout << "graph" << endl;
    g.print();

    cout << "parents" << endl;
    g.printParents();

    ans = g.dfs(0, n, labels);

    return ans;
}

int main(){
    return 0;
}


