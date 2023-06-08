#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comparator(pair <int, int> first, pair <int, int> second){
    if (first.second < second.second){
        return false;
    }else if(first.second > second.second){
        return true;
    }else{
        if (first.first >= second.first){
            return false;
        }else{
            return true;
        }
    }
}


int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    vector <pair <int, int>> hold;
    for (int i = 0; i < plantTime.size(); i++){
        hold.push_back({plantTime[i], growTime[i]});
    }

    sort(hold.begin(), hold.end(), comparator);

    for (int i = 0; i < hold.size(); i++){
        cout << hold[i].first << " " << hold[i].second << endl;
    }

    int limiter = 0;
    int starter = 0;
    for (int i = 0; i < hold.size(); i++){
        int holder = starter + hold[i].first + hold[i].second;
        if (holder > limiter){
            limiter = holder;
        }
        starter += hold[i].first;
    }

    return limiter;
}

int main(){
    return 0;
}