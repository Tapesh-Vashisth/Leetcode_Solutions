#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static bool compare(string first, string second){
    if (first.size() >= second.size()){
        return false;
    }else{
        return true;
    }
}

int findmax(unordered_map <string, int>& mapping, string word){
    int mx = -1;
    for (int i = 0; i < word.size(); i++){
        string hold = word.substr(0, i) + word.substr(i + 1);

        if (mapping.count(hold)){
            mx = max(mapping[hold] + 1, mx);
        }
    }

    if (mx == -1){
        return 1;
    }

    return mx;
}

int longestStrChain(vector<string>& words){
    unordered_map <string, int> mapping;
    mapping[""] = 0;
    sort(words.begin(), words.end(), compare);

    int ans = 0;

    for (int i = 0; i < words.size(); i++){
        cout << words[i] << endl;
        mapping[words[i]] = findmax(mapping, words[i]);
        ans = max(ans, mapping[words[i]]);        
    }

    return ans;
}

int main(){
    vector<string> v = {"czgxmxrpx","lgh","bj","cheheex","jnzlxgh","nzlgh","ltxdoxc","bju","srxoatl","bbadhiju","cmpx","xi","ntxbzdr","cheheevx","bdju","sra","getqgxi","geqxi","hheex","ltxdc","nzlxgh","pjnzlxgh","e","bbadhju","cmxrpx","gh","pjnzlxghe","oqlt","x","sarxoatl","ee","bbadju","lxdc","geqgxi","oqltu","heex","oql","eex","bbdju","ntxubzdr","sroa","cxmxrpx","cmrpx","ltxdoc","g","cgxmxrpx","nlgh","sroat","sroatl","fcheheevx","gxi","gqxi","heheex"};
    cout << longestStrChain(v) << endl;
    return 0;
}