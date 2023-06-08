#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
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
                    cout << hold << " ";
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

        int minpathHelper(int current, vector <int>& visited, int target){
            if (current == target){
                return 0;
            }
            if (visited[current] == 0){
                visited[current] = 1;

                int mn = 1 << 30;
                for (auto x: l[current]){
                    int hold = minpathHelper(x, visited, target);
                    if (hold != -1){
                        if (hold < mn){
                            mn = hold;
                        }
                    }
                }

                if (mn == (1 << 30)){
                    return -1;
                }

                return mn + 1;
            }else{
                return -1;
            }
        }

        int minpath(int source, int destination){
            vector <int> visited(v, 0);
            int ans = minpathHelper(source, visited, destination);
            return ans;
        }
};


bool check(string s1, string s2){
    if (s1.size() != s2.size()){
        return false;
    }else{
        int counter = 0;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]){
                counter++;
            }
        }

        if (counter == 1){
            return true;
        }

        return false;
    }
}


int minMutation(string start, string end, vector<string>& bank){
    int maxlen = 8;
    unordered_set <string> str;
    str.insert(start);
    int decider = 0;
    for (int i = 0; i < bank.size(); i++){
        if (end == bank[i]){
            decider = 1;
        }
        str.insert(bank[i]);
    }
    
    if (decider == 0){
        return -1;
    }

    int distinct = str.size();
    unordered_map <string, int> mapping;
    auto it = str.begin();
    int counter = 0;
    for (; it != str.end(); it++){
        mapping.insert({*it, counter++});
    } 

    graph g(distinct);

    // neighbours 
    it = str.begin();
    for (; it != str.end(); it++){
        auto it2 = it;
        for (; it2 != str.end(); it2++){
            bool decider = check(*it, *it2);
            if (decider){
                g.addEdge(mapping[*it], mapping[*it2]);
            }
        }
    }

    int source = mapping[start];
    int destination = mapping[end];
    return g.minpath(source, destination);
}


int main(){
    return 0;
}