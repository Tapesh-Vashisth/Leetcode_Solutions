#include <iostream>
#include <vector>
using namespace std;

int decider = 0;

vector <string> storage;

bool wordBreak_helper(string s, vector <string>& wordDict){
    if (s.empty()){
        return true;
    }else{
        bool decider = false;

        for (int i = 0; i < wordDict.size(); i++){
            if (s.size() >= wordDict[i].size() && s.substr(0, wordDict[i].size()) == wordDict[i]){
                bool temp = wordBreak_helper(s.substr(wordDict[i].size()), wordDict);
                if (temp == true){
                    decider = true;
                }
            }
        }

        return decider;
    }   
}

bool wordBreak(string s, vector<string>& wordDict){
    cout << wordBreak_helper(s, wordDict) << endl;
}

int main(){
    vector <string> v = {"cats", "dog", "sand", "and", "cat"};
    wordBreak("catsandog", v);
    return 0;
}