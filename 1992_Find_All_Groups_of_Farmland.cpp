#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector <vector <int>> ans;

    vector <vector <int>> store(land.size(), vector <int> (land[0].size(), -1));

    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            if (land[i][j] == 1) {
                int index = -1;
                // up 
                if (i - 1 >= 0) {
                    index = store[i - 1][j];
                }

                // left 
                if (j - 1 >= 0 && index == -1) {
                    index = store[i][j - 1];
                }

                if (index == -1) {
                    vector <int> temp = {i, j};
                    ans.push_back(temp);
                    store[i][j] = ans.size() - 1;
                } else {
                    store[i][j] = index;
                }

                bool check = false;
                // down 
                if (i + 1 < land.size() && land[i + 1][j] == 1) {
                    check = true;
                }

                // right 
                if (j + 1 < land[i].size() && land[i][j + 1] == 1) {
                    check = true;
                }

                if (check == false) {
                    ans[store[i][j]].push_back(i);
                    ans[store[i][j]].push_back(j);
                }
            }
        }
    }

    return ans;
}  

int main() {
    return 0;
}