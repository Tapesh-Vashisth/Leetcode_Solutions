#include <bits/stdc++.h>
using namespace std;

vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> res;
    while (!ss.eof()) {
        getline(ss, word, del);
        res.emplace_back(word);
    }
    return res;
}

static bool comparator(vector <string> first, vector <string> second) {
    return first[0] < second[0];
}

vector<string> invalidTransactions(vector<string>& transactions) {
    set <string> ans;
    // removing invalid greater than 1000 and fill the map
    map<string,vector<vector<string>>> m;
    for (auto &it: transactions) {
        vector<string> hold = adv_tokenizer(it, ',');
        if(stoi(hold[2]) > 1000){
            ans.insert(it); 
        }
        else{
            m[hold[0]].push_back({hold[1],hold[2],hold[3]});
        }
    }

    for (auto &it: m) {
        sort(it.second.begin(), it.second.end(), comparator);
    }

    for (auto it: m) {
        vector <vector <string>>& hold = it.second;
        for (int i = 0; i < hold.size(); i++) {
            for (int j = i + 1; j < hold.size(); j++) {
                if (stoi(hold[j][0]) - stoi(hold[i][0]) > 60) {
                    break;
                } else {
                    if (hold[j][2] != hold[i][2]) {
                        string temp = it.first;
                        temp = temp + ",";
                        for (int a = 0; a < hold[j].size(); a++) {
                            temp = temp + hold[j][a];
                            temp = temp + ",";
                        }
                        temp.pop_back();
                        ans.insert(temp);

                        temp = it.first;
                        temp = temp + ",";
                        for (int a = 0; a < hold[i].size(); a++) {
                            temp = temp + hold[i][a];
                            temp = temp + ",";
                        }
                        temp.pop_back();
                        ans.insert(temp);
                    }
                }
            }
        }
    }

    vector <string> realans;
    for (auto it: ans) {
        realans.push_back(it);
    }

    return realans;
}

int main() {
    return 0;
}