#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class DSU {
    private:
        vector <int> parent;

    public:
        DSU(int n) {
            parent.resize(n);
            for(int i = 0; i<n; i++) parent[i] = i;
        }

        int find(int ele) {
            if (parent[ele] == ele) {
                return ele;
            } 

            int par = find(parent[ele]);

            parent[ele] = par;

            return par;
        }


        void U(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            
            if (p1 != p2) {
                parent[p1] = p2;
            }
        }

        int groups() {
            set <int> store; 
            for (int i = 0; i < parent.size(); i++) {
                store.insert(find(i));
            }

            return store.size();
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << i << " " << parent[i] << endl;
            }
        }
};

bool canTraverseAllPairs(vector<int>& nums) {
    if (nums.size() == 1) {
        return true;
    }

    sort(nums.begin(), nums.end());
    DSU dsu(nums.size());

    vector <int> hash(1e5 + 5, -1);


    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            return false;
        }

        for (int j = 2; j * j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                if (hash[j] == -1) {
                    hash[j] = i;
                } else {
                    dsu.U(i, hash[j]);
                }

                if (hash[nums[i] / j] == -1) {
                    hash[nums[i] / j] = i;
                } else {
                    dsu.U(i, hash[nums[i] / j]);
                }
            }
        }

        if (hash[nums[i]] == -1) {
            hash[nums[i]] = i;
        } else {
            dsu.U(i, hash[nums[i]]);
        }
    }      


    return dsu.groups() == 1;    
}

int main() {
    return 0;
}