#include<bits/stdc++.h>

using namespace std;

static bool comp(vector<int> &v1,vector<int>&v2){
    return v1[1] > v2[1];
}

static bool comp2(vector<int> &v1,vector<int>&v2){
    return v1[1] < v2[1];
}


vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    //prefix set
    set <int> s;
    map <vector <int>, int> mapped;
    for (int i = 0; i < queries.size(); i++) {
        mapped[queries[i]] = i;
    }

    sort(queries.begin(),queries.end(),comp);
    sort(rooms.begin(),rooms.end(),comp2);
    vector <pair <int, int>> store;

    for (auto it: rooms) {
        store.push_back({it[1], it[0]});
    }

    for(auto it : store){
        cout << it.first << ' ' << it.second << '\n';
    }

    vector <int> ans(queries.size(), -1);

    int current = store.size();
    for(auto it : queries){
        int pos = lower_bound(store.begin(), store.end(), make_pair(it[1], 0)) - store.begin();
        if (pos == store.size()) {
            ans[mapped[it]] = -1;
        } else {
            for (int i = pos; i < current; i++) {
                s.insert(store[i].second);
            }
            current = pos;

            auto decider = s.lower_bound(it[0]);
            if (decider == s.end()) {
                ans[mapped[it]] = *(--s.end());
            } else {
                if (*decider == it[0]) {
                    ans[mapped[it]] = it[0];
                } else if (decider != s.begin()) {
                    auto holder = decider;
                    if (abs(*(--decider) - it[0]) < abs(*holder - it[0])) {
                        ans[mapped[it]] = *decider;
                    } else {
                        ans[mapped[it]] = *holder;
                    }
                } else {
                    ans[mapped[it]] = *decider;
                }
            } 
        }
    }

    return ans;
}

int main(){

    return 0;
}