#include <iostream>
#include <vector>
using namespace std;

vector <int> helper(int n, int i){
    vector <int> ret;
    if (i == n){
        ret.push_back(0);
        return ret;
    }else{
        // included 
        ret = helper(n, i + 1);

        // not included 
        int len = ret.size();
        for (int j = 0; j < len; j++){
            ret.push_back(ret[j] + 1);
        }

        return ret;
    }
}

int totalbits(int n){
    int counter = 0;
    while (n){
        counter++;
        n = n>>1;
    }

    return counter;
}

vector<int> countBits(int n){
    int counter = totalbits(n);
    vector <int> ans = helper(counter, 0);
    for (int i = 0; i < counter; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    ans.resize(n);
    return ans;
}

int main(){
    return 0;
}