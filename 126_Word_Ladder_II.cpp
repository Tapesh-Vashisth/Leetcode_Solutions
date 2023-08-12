#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool positionDiffer(string &first, string &second) {
    int n = first.length();
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(first[i]!=second[i]) count++;
        if(count > 1) return false; 
    }
    if(count) return true;
    return false;
}

void backtrack(int node, int start, vector <vector <int>> & parents, vector <vector <int>> & ans, vector <int> & temp) {
    if (node == start) {
        temp.push_back(node);
        ans.push_back(temp);
        temp.pop_back();

        return ;
    }

    for (int i = 0; i < parents[node].size(); i++) {
        temp.push_back(node);
        backtrack(parents[node][i], start, parents, ans, temp);
        temp.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector <vector <string>> realans;
    bool check = false;
    int index = 0;
    int counter = 0;
    int target = -1;
    for (auto & it: wordList) {
        if (it == beginWord) {
            index = counter;
            check = true;
        }
        if(it == endWord) {
            target = counter;
        }
        counter++;
    }


    if (!check) {
        index = wordList.size();
        wordList.push_back(beginWord);
    } 

    if (target == -1) {
        return realans;
    }

    vector <int> graph [wordList.size()];      
    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i + 1; j < wordList.size(); j++) {
            if (positionDiffer(wordList[i], wordList[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }      
        }
    }   


    set <pair <int, int>> pq;
    pq.insert({0, index});
    vector <int> dists(wordList.size(), 1e8);
    vector <vector <int>> routes(wordList.size());
    dists[index] = 0;
    while (!pq.empty()) {
        auto pos = pq.begin();
        pair <int, int> hold = (*pos);
        pq.erase(pos);

        for (auto & it: graph[hold.second]) {
            if (hold.first + 1 < dists[it]) {
                routes[it].clear();
                routes[it].push_back(hold.second);
                pq.erase({dists[it], it});
                dists[it] = hold.first + 1;
                pq.insert({dists[it], it});
            } else if (hold.first + 1 == dists[it]) {
                routes[it].push_back(hold.second);
                pq.insert({dists[it], it});
            }
        }
    }


    vector <vector <int>> temp; 
    vector <int> hold;
    backtrack(target, index, routes, temp, hold);

    vector <vector <string>> ans;
    for (int i = 0; i < temp.size(); i++) {
        vector <string> ah;
        reverse(temp[i].begin(), temp[i].end());
        for (int j = 0; j < temp[i].size(); j++) {
            ah.push_back(wordList[temp[i][j]]);
        }
        ans.push_back(ah);
    }

    return ans;
}

int main() {
    return 0;
}