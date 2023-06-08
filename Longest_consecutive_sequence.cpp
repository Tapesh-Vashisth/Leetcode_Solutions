#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestConsecutive(vector<int>& nums){
    map <int, int> m;
    
    for (int i = 0; i < nums.size(); i++){
        m[nums[i]] = 1;
    }

    int maxlen = 0;

    map <int, int> :: iterator it = m.begin();

    while (it != m.end()){
        int len = 1;
        int prev = (*it).first;
        it++;
        while (it != m.end()){
            if ((*it).first - prev == 1){
                len++;
                if (len > maxlen){
                    maxlen = len;
                }
                prev = (*it).first;
                it++;
            }else{
                break;
            }
        }
    }

    return maxlen;
}

int main(){
    vector <int> v = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(v) << endl;
    return 0;
}