#include <iostream>
#include <vector>
using namespace std;

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets){
    string ansstr = s;
    for (int i = 0; i < indices.size(); i++){
        string first = s.substr(indices[i], sources[i].size());
        string second = sources[i];
        cout << first << " " << second << endl;
        ansstr.erase(indices[i], sources[i].size());
        ansstr.insert(indices[i], targets[i]);
        for (int j = i; j < indices.size(); j++){
            indices[j] = indices[j] - sources[i].size() + targets[i].size();
        }
    }
    cout << ansstr << endl;
    return ansstr;
}

int main(){
    return 0;
}