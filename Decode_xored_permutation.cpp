#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> decode(vector<int>& encoded){
    vector <int> ans;
    int len = encoded.size() + 1;
    int decider = 0;
    for (int i = 1; i <= len; i++){
        decider = decider ^ i;
    }

    int last = decider;
    for (int i = 0; i < encoded.size(); i = i + 2){
        last = last ^ encoded[i];
    }
    ans.push_back(last);
    for (int i = encoded.size() - 1; i >= 0; i--){
        last = last ^ (encoded[i]);
        ans.push_back(last);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector <int> v = {6,5,4,6};
    v = decode(v);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}