#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int>> storage;

void helper(vector <int>& arr, int index, int value, int check, int start){
    if (index >= arr.size()){
        if (value == 0){
            storage.push_back({start, index - 1});
        }else{
            ;
        }
    }else{
        if (value == 0){
            storage.push_back({start, index - 1});
        }else{
            // not including 
            if (check == 0){
                helper(arr, index + 1, value, 0, index);
            }

            // including
            int s;
            if (check == 0){
                s = index;
            }else{
                s = start;
            }
            helper(arr, index + 1, value - arr[index], arr[index], s);
        }
    }
}

bool comparator(pair <int, int> first, pair <int, int> second){
    int dif1 = first.second - first.first;
    int dif2 = second.second - second.first;
    return dif1 < dif2;
}

int minSumOfLengths(vector<int>& arr, int target){
    storage.clear();
    helper(arr, 0, target, 0, 0);

    for (int i = 0; i < storage.size(); i++){
        cout << storage[i].first << " " << storage[i].second << endl;
    }

    if (storage.size() < 2){
        return -1;
    }else{
        sort(storage.begin(), storage.end(), comparator);
        cout << "alert" << endl;
        for (int i = 0; i < storage.size(); i++){
            cout << storage[i].first << " " << storage[i].second << endl;
        }

        
    }
}

int main(){
    vector <int> v = {3, 4, 1, 5, 1, 1, 3};
    cout << minSumOfLengths(v, 5) << endl;
    return 0;
}