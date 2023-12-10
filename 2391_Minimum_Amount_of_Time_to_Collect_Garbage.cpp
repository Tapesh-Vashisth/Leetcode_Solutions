#include <iostream>
#include <vector>
using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    vector <char> types = {'M', 'P', 'G'};

    int ans = 0;
    for (auto it: types) {
        int current = 0;
        for (int i = 0; i < garbage.size(); i++) {
            bool flag = false;
            for (int j = 0; j < garbage[i].size(); j++) {
                if (garbage[i][j] == it) {
                    if (flag == false) {
                        flag = true;
                        ans += current;
                        current = 0;
                    }

                    ans += 1;
                }
            }        

            if (i != garbage.size() - 1) {
                current += travel[i];
            }
        }
    }        

    return ans;
}

int main() {
    return 0;
}