#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    bool end;
    int index;
    node * routes[26];

    node() {
        end = false;
        index = -1;
        for (int i = 0; i < 26; i++) {
            routes[i] = NULL;
        }
    }       
};

class Trie {
public:
    node * root;

    Trie() {
        root = new node();
    }

    void insert(string & word, int index) {
        node * hold = root;
        for (auto it: word) {
            if (hold->routes[it - 'a'] != NULL) {
                hold = hold->routes[it - 'a'];
            } else {
                node * temp = new node();
                hold->routes[it - 'a'] = temp;
                hold = hold->routes[it - 'a'];
            }
        }

        hold->end = true;
        hold->index = index;
    }

    int search(string & word) {
        node * hold = root;
        for (auto it: word) {
            if (hold->routes[it - 'a'] != NULL) {
                hold = hold->routes[it - 'a'];
            } else {
                return -1;
            }
        }

        if (hold->end == true) {
            return hold->index;
        }

        return -1;
    }

    bool startsWith(string & prefix) {
        node * hold = root;
        for (auto it: prefix) {
            if (hold->routes[it - 'a'] == NULL) {
                return false;
            }
            hold = hold->routes[it - 'a'];
        }

        return true;
    }

    ~Trie() {
        delete root;
    }
};

long long getithbit(long long x, long long i){
    long long bit = (long long)1 << (i - 1);
    return (x & bit ? 1 : 0);
}

long long clearithbit(long long x, long long i){
    long long bit = ~((long long)1 << (i - 1));
    return (x & bit);
}

long long setithbit(long long x, long long i){
    return (x | ((long long)1 << (i - 1)));
}

vector <vector <pair <int, string>>> dp;

pair <int, string> helper (vector <int> & people, int current, int target, int index) {
    if (index >= people.size()) {
        if (current == target) {
            return {0, ""};
        } else {
            return {INT32_MAX, ""};
        }
    }

    if (dp[index][current].first != -1) {
        return dp[index][current];
    }

    // take 
    pair <int, string> take = helper(people, current | people[index], target, index + 1);
    // not take  
    pair <int, string> notTake = helper(people, current, target, index + 1);

    if (take.first < notTake.first) {
        take.second.push_back('0' + index);

        dp[index][current] = {take.first + 1, take.second};
        return {take.first + 1, take.second};
    } else {
        dp[index][current] = notTake;
        return notTake;
    }
}

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    Trie t;

    for (int i = 0; i < req_skills.size(); i++) {
        t.insert(req_skills[i], i);
    }

    vector <int> store;
    for (auto & it: people) {
        int mask = 0;
        for (int i = 0; i < it.size(); i++) {
            int hold = t.search(it[i]);
            mask = setithbit(mask, hold + 1);
        }
        store.push_back(mask);
    }


    dp = vector <vector <pair <int, string>>> (people.size() + 2, vector <pair <int, string>> ((1 << req_skills.size()) + 5, {-1, ""}));
    pair <int, string> hold = helper(store, 0, (1 << req_skills.size()) - 1, 0);

    vector <int> ans;
    for (auto it: hold.second) {
        ans.push_back(it - '0');
    }

    return ans;
}

int main() {
    return 0;
}