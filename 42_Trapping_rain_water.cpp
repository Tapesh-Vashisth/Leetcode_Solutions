#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// int trap(vector<int>& height){
//     queue <int> storage;
//     int ans = 0;
//     storage.push(height[0]);
//     int middle = 0;
//     for (int i = 1; i < height.size(); i++){
//         if (height[i] < storage.front()){
//             storage.push(height[i]);
//         }else{
//             middle = i;
//             int caught = storage.front();
//             storage.pop();
//             int last = height[i];
//             while (!storage.empty()){
//                 if (storage.front() <= caught){
//                     ans += caught - storage.front();
//                 }
//                 storage.pop();
//             }
//             storage.push(last);
//         }
//     }

//     while (!storage.empty()){
//         storage.pop();
//     }

//     storage.push(height[height.size() - 1]);
//     for (int i = height.size() - 2; i >= middle; i--){
//         if (height[i] < storage.front()){
//             storage.push(height[i]);
//         }else{
//             int caught = storage.front();
//             storage.pop();
//             int last = height[i];
//             while (!storage.empty()){
//                 if (storage.front() <= caught){
//                     ans += caught - storage.front();
//                 }
//                 storage.pop();
//             }
//             storage.push(last);
//         }
//     }

//     return ans;
// }



int trap(vector <int>& height) {
    vector <int> maxRight;
    vector <int> maxLeft;
    stack <int> store;

    for (int i = height.size() - 1; i >= 0; i--) {
        if (store.empty()) {
            maxRight.push_back(height.size());
            store.push(i);
        } else {
            while (!store.empty() && height[store.top()] < height[i]) {
                store.pop();
            }

            if (store.empty()) {
                maxRight.push_back(height.size());
                store.push(i);
            } else {
                maxRight.push_back(store.top());
            }
        }
    }

    reverse(maxRight.begin(), maxRight.end());

    store = stack<int> ();
    for (int i = 0; i < height.size(); i++) {
        if (store.empty()) {
            maxLeft.push_back(height.size());
            store.push(i);
        } else {
            while (!store.empty() && height[store.top()] < height[i]) {
                store.pop();
            }

            if (store.empty()) {
                maxLeft.push_back(height.size());
                store.push(i);
            } else {
                maxLeft.push_back(store.top());
            }
        }
    }


    for (auto it: maxLeft) {
        cout << it << " ";
    }

    cout << endl;

    int ans = 0;

    for (int i = 0; i < height.size(); i++) {
        if (maxRight[i] != height.size() && maxLeft[i] != height.size()) {
            ans += min(height[maxRight[i]], height[maxLeft[i]]) - height[i];
        }
    }

    return ans;
}


int main(){
    vector <int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v) << endl;
    return 0;
}