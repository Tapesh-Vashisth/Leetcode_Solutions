#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DSU {
    private:
        map <pair <int, int>, pair <int, int>> parent;

    public:
        DSU(vector <vector <int>> & stones) {
            for(int i = 0; i < stones.size(); i++) {
                parent[{stones[i][0], stones[i][0]}] = {stones[i][0], stones[i][1]};
            } 
        }

        pair <int, int> find(pair <int, int> ele) {
            if (parent[ele] == ele) {
                return ele;
            } 

            pair <int, int> par = find(parent[ele]);

            parent[ele] = par;

            return par;
        }


        void U(pair <int, int> a, pair <int, int> b) {
            pair <int, int> p1 = find(a);
            pair <int, int> p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            
            if (p1 != p2) {
                parent[p1] = p2;
            }
        }

        int counter () {
            int total = 0;
            for (auto it: parent) {
                if (it.first == it.second) {
                    total++;
                }
            }

            return total;
        }

        void print() {
            ;
        }
};


int removeStones(vector<vector<int>>& stones) {
    DSU dsu(stones);

    for (int i = 0; i < stones.size(); i++) {
        for (int j = i + 1; j < stones[i].size(); j++) {
            if (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]) {
                dsu.U({stones[i][0], stones[i][1]}, {stones[j][0], stones[j][1]});
            }
        }
    }

    int counter = dsu.counter();

    return stones.size() - counter;
}

int main(){
    return 0;
}