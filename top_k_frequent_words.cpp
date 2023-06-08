#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(pair<string, int> first, pair <string, int> second){
    if (first.second > second.second){
        return true;
    }else if(first.second < first.second){
        return false;
    }else{
        if (first.first > second.first){
            return true;
        }else{
            return false;
        }
    }
}

vector<string> topKFrequent(vector<string>& words, int k){
    unordered_map <string, int> storage;
    for (int i = 0; i < words.size(); i++){
        storage[words[i]]++;
    }

    vector <pair <string, int>> v;
    auto it = storage.begin();

    for (; it != storage.end(); it++){
        if ((*it).second >= k){
            v.push_back({(*it).first, (*it).second});
        }
    }

    sort(v, comparator);

    vector <int> ans;
    for (int i = 0; i < v.size(); i++){
        ans.push_back(v[i].first);
    }

    return ans;
}

int main(){
    
    return 0;
}