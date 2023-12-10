#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector <vector <int>> store = {{1}};

    for (int i = 1; i <= rowIndex; i++) {
        vector <int> temp = {1};
        for (int j = 0; j < i - 1; j++) {
            temp.push_back(store[i - 1][j] + store[i - 1][j + 1]);
        }

        temp.push_back(1);
        store.push_back(temp);
    }       

    return store[rowIndex]; 
}

int main() {
    return 0;
}