#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k){
    vector <int> hash(1001, 0);

    for (int i = 0; i < arr.size(); i++){
        hash[arr[i]] = 1;
    }

    int counter = 0;
    for (int i = 1; i < 1001; i++){
        if (hash[i] == 0){
            counter++;
        }

        if (counter == k){
            break;
        }
    }

    return counter;
}

int main(){
    return 0;
}