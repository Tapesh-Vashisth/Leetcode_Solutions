#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class DSU {
    public:
        map <string, pair <string, int>> parentEmail;
        map <pair <string, int>, pair <string, int>> parentParent;
        DSU(vector <vector <string>> accounts) {
            for (int i = 0; i < accounts.size(); i++) {
                parentParent[{accounts[i][0], i}] = {accounts[i][0], i};
            }
        }

        pair <string, int> find(pair <string, int> ele) {
            if (parentParent[ele] == ele) {
                return ele;
            } 

            pair <string, int> par = find(parentParent[ele]);

            parentParent[ele] = par;

            return par;
        }


        void U(pair <string, int> user, string email) {
            pair <string, int> p1 = find(user);

            if (parentEmail[email].first == "") {
                parentEmail[email] = p1;
            } else {
                pair <string, int> p2 = find(parentEmail[email]);

                if (p1 != p2) {
                    parentParent[p2] = p1;
                }
            }
        }

        void print() {
            for (auto it: parentParent) {
                cout << it.first.first << " - " << it.first.second << " ---> " << it.second.first << " - " << it.second.second << endl;
            }
        }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    DSU dsu(accounts);
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            dsu.U({accounts[i][0], i}, accounts[i][j]);
        }
    }


    vector <vector <string>> ans;
    
    map <pair <string, int>, set <string>> store;
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            pair <string, int> parent = dsu.find(dsu.parentEmail[accounts[i][j]]);
            store[parent].insert(accounts[i][j]);
        }
    }

    for (auto it: store) {
        if (it.second.size() > 0) {
            vector <string> temp;
            temp.push_back(it.first.first);
            for (auto it2: it.second) {
                temp.push_back(it2);
            }

            ans.push_back(temp);
        }
    }

    return ans;
}

int main() {
    return 0;
}