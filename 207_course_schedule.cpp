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

        bool dfsHelper(int root, vector <bool>& visited, vector <bool>& mainVisited){
            if (visited[root] == false){
                visited[root] = true;
                mainVisited[root] = true;
                bool ret = false;
                for (auto hold: this->l[root]){
                    bool temp = dfsHelper(hold, visited, mainVisited);
                    if (temp) {
                        ret = true;
                        break;
                    }
                }

                return ret;
            } else {
                return true;
            }
        }

        bool circleCheck(){
            vector <bool> mainVisited(this->v, false);
            for (int i = 0; i < this->v; i++) {
                if (mainVisited[i] == false) {
                    vector <bool> visited(this->v, false);
                    bool decider = dfsHelper(i, visited, mainVisited);
                    if (decider) {
                        return true;
                    }
                }
            }

            return false;
        }
};

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);
    for (int i = 0; i < prerequisites.size(); i++) {
        g.addEdge(prerequisites[i][0], prerequisites[i][1], false);
    }

    g.print();

    return g.circleCheck();
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // kahn's algorithm 
    vector <int> indegree(numCourses, 0);
    
    vector <vector <int>> gh(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) {
        gh[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }       

    queue <int> store;     

    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            store.push(i);
        }
    }

    vector <int> topo;

    while (!store.empty()) {
        int hold = store.front();
        store.pop();
        topo.push_back(hold);

        for (int i = 0; i < gh[hold].size(); i++) {
            indegree[gh[hold][i]]--;
            if (indegree[gh[hold][i]] == 0) {
                store.push(gh[hold][i]);
            }
        }
    }

    if (topo.size() < numCourses) {
        return false;
    }

    return true;
}

int main() {
    return 0;
}