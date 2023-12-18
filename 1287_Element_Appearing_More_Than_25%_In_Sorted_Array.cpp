#include <iostream>
#include <vector>
using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int index = 0;

    double thres = arr.size() / 4.0;
    while (index < arr.size()) {
        int counter = 1;
        int hold = arr[index];
        while (index + 1 < arr.size() && arr[index] == arr[index + 1]) {
            index++;
            counter++; 
        }


        if (counter > thres) {
            return hold;
        }

        index++;
    }        


    return -1;
}

int main() {
    return 0;
}