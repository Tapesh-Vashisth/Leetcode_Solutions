#include <iostream>
#include <vector>
#include <set>
using namespace std;

int distributeCandies(vector<int> candies){
    set <int> store;
    for (int i = 0; i < candies.size(); i++){
        store.insert(candies[i]);
    }
    if (store.size() >= candies.size()/2){
        return candies.size()/2;
    }else{
        return store.size();
    }
}

int main(){
    vector <int> v = {1, 1, 1, 1, 1};
    cout << distributeCandies(v) << endl;
    return 0;
}