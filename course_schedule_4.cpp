#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class graph{
    list <int> * l;
    int v;
    unordered_map <int, int> related;
    
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

        vector <int> dfsHelper(int root, vector <bool>& visited, vector <bool> & mainVisited){
            if (visited[root] == false){
                visited[root] = true;
                mainVisited[root] = true;
                vector <int> total;
                for (auto hold: this->l[root]){
                    vector <int> temp = dfsHelper(hold, visited, mainVisited);
                    for (int i = 0; i < temp.size(); i++) {
                        related[hold] = temp[i];
                        total.push_back(temp[i]);
                    }
                }

                total.push_back(root);

                return total;
            } else {
                vector <int> ret;
                return ret;
            }
        }

        void dfs(){
            vector <bool> mainVisited(this->v, false);
            for (int i = 0; i < this->v; i++) {
                if (mainVisited[i] == false) {
                    vector <bool> visited(this->v, false);
                    dfsHelper(i, visited, mainVisited);       
                }
            }

            for (auto it = related.begin(); it != related.end(); it++) {
                cout << (*it).first << " " << (*it).second << endl;
            }
        }
};

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    graph g(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) {
        g.addEdge(prerequisites[i][0], prerequisites[i][1], false);
    }

    g.print();

    g.dfs();

    vector <bool> ans;
    return ans;
}

int main() {
    return 0;
}