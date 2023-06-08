#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector <vector <string>> ans;
    set <string> container;

    for (auto it: wordList) {
        container.insert(it);
    }

    int mn = -1;
    queue <pair <string, vector <string>>> store;

    store.push({beginWord, {beginWord}});       
    unordered_map <string, int> visited;
    visited[beginWord] = 0;

    while (!store.empty()) {
        pair <string, vector <string>> hold = store.front();
        store.pop();

        if (hold.first == endWord && (mn == -1 || hold.second.size() == mn)) {
            mn = hold.second.size();
            ans.push_back(hold.second);
        }

        if (hold.second.size() <= visited[hold.first]) {
            visited[hold.first] = hold.second.size();

            for (int i = 0; i < hold.first.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string temp = hold.first;
                    temp[i] = 'a' + i;

                    if (temp != hold.first && container.find(temp) != container.end()) {
                        hold.second.push_back(temp);
                        store.push({temp, hold.second});
                        hold.second.pop_back();
                    }
                }
            }
        }    
    }

    return ans;
}

int main() {
    return 0;
}