#include <iostream>
#include <vector>
using namespace std;


bool check(string & s, int start, int end){
    while (start < end){
        if (s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}



string longestPalindrome(string s){
    vector <vector <int>> hash(100);
    int front = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++){
        int init = s[i] - '0';
        if (hash[init].size() == 0){
            hash[init].push_back(i);
        }else{
            for (int j = 0; j < hash[init].size(); j++){
                if (check(s, hash[init][j], i)){
                    if (i - hash[init][j] > end - front){
                        front = hash[init][j];
                        end = i;
                    }
                    break;
                }
            }

            hash[init].push_back(i);
        }
    }

    return s.substr(front, end - front + 1);
}


int main(){
    cout << longestPalindrome("babad") << endl;
    return 0;
}


// bool check(string s, int first, int second){
//     int low = first;
//     int high = second + 1;
//     while (low < high){
//         if (s[low] != s[high]){
//             return false;
//         }

//         low++;
//         high--;
//     }

//     return true;

// }

// string longestPalindrome(string s){
//     vector <pair <int, int>> store = {{0, 0}};
//     for (int i = 1; i < s.size(); i++){
//         for (int j = store.size() - 1; j >= 0; j--){
//             int decider = 1;
//             if (i - store[j].second == 1){
//                 if (store[j].first != 0){
//                     if (s[store[j].first - 1] == s[i]){
//                         decider = 0;
//                         store[j].first--;
//                         store[j].second++;
//                     }
//                 }

//                 if (decider == 1){
//                     if (check(s, store[j].first, store[j].second)){
//                         store[j].second++;
//                     }
//                 }
//             }else{
//                 break;
//             }

//         }
//         store.push_back({i, i});
//     }

//     for (int i = 0; i < store.size(); i++){
//         cout << store[i].first << " " << store[i].second << endl;
//     }

//     string mx = "";

//     for (int i = 0; i < store.size(); i++){
//         if (store[i].second - store[i].first + 1 > mx.size()){
//             mx = s.substr(store[i].first, store[i].second - store[i].first + 1);
//         }
//     }

//     return mx;
// }
