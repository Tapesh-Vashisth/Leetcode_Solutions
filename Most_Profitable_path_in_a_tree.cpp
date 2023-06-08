#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class graph{
    list <int> * l;
    int v;
    vector <int> path;
    int ans;

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

        void dfsHelper(int root, vector <bool>& visited, int collection, vector <int>& amount, int bob){
            if (visited[root] == false){
                visited[root] = true;
                collection += amount[root];
                path.push_back(root);

                if (root == bob) {
                    int left = 0;
                    int right = path.size()-1;
                    int newcollect = 0;
                    while (left <= right) {
                        if (left == right) {
                            newcollect += amount[left]/2;
                        } else {
                            newcollect += amount[left];
                        }
                        left++;
                        right--;
                    }
                    collection = newcollect;           
                } else {
                    if (l[root].size() == 1 && root != 0) {
                        ans = max(ans, collection);                    
                    }
                }

                for (auto hold: this->l[root]){
                    dfsHelper(hold, visited, collection, amount, bob);
                }

                path.pop_back();
            }
        }

        int dfs(int source, vector <int> &amount, int bob){
            path.clear();
            ans = INT_MIN;
            vector <bool> visited(this->v, false);
            dfsHelper(source, visited, amount[0], amount, bob);

            return ans;
        }
};

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    graph g(amount.size());
    for (auto it: edges) {
        g.addEdge(it[0], it[1], true);
    }

    g.print();

    return g.dfs(0, amount, bob);
}
 
int main() {
    return 0;
}