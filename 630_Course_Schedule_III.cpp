#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

static bool comparator(vector <int> first, vector <int> second) {
        if (second[1] > first[1]) {
            return true;
        } else if(second[1] == first[1]) {
            if (second[0] >= first[0]) {
                return true;
            }
        }

        return false;
}

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), comparator);
    map <int, int> store;

    priority_queue <int, vector<int>, greater<int>> gq;

    for (int i = 0; i < courses.size(); i++) {
        for (int j = 0; j < courses[i].size(); j++) {
            cout << courses[i][j] << " ";
        }
        cout << endl;
    }

    int total = 0;
    int ans = 0;

    for (int i = 0; i < courses.size(); i++) {
        if (total + courses[i][0] <= courses[i][1]) {
            ans++;
            total += courses[i][0];
            store[courses[i][0]]++;
        } else if (store.size() > 0) {
            int mxDuration = (*(--store.end())).first;
            
            if (courses[i][0] < mxDuration) {
                total -= mxDuration;
                total += courses[i][0];
                store[mxDuration]--;
                if (store[mxDuration] == 0) {
                    store.erase(mxDuration);
                }
                store[courses[i][0]]++;
            }
        }
    }

    return ans;
}

int main(){
    return 0;
}