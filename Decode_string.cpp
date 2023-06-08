#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    string ansstr = s;
    for (int i = 0; i < indices.size(); i++){
        ansstr.erase(indices[i], sources[i].size());
        ansstr.insert(indices[i], targets[i]);
        for (int j = i; j < indices.size(); j++){
            indices[j] = indices[j] - sources[i].size() + targets[i].size();
        }
    }
    cout << ansstr << endl;
    return ansstr;
}

string medium(string s, int start, int end){
    vector<int> indexes;
    stack <int> buffer;
    for (int i = start; i < end; i++){
        if (buffer.empty() && s[i] == '['){
            indexes.push_back(i + 1);
        }
        if (s[i] == '['){
            buffer.push('[');
        }else if(s[i] == ']'){
            buffer.pop();
        }

        if (buffer.empty() && s[i] == ']'){
            indexes.push_back(i);
        }
    }


    if (indexes.size() == 0){
        return s.substr(start, end - start);
    }

    vector <int> subs;

    for (int i = 0; i < indexes.size(); i++){
        subs.push_back(indexes[i] - start - 2);
    }

    for (auto i : subs){
        cout << i << " ";
    }
    cout << endl;

    vector <string> replacement;
    string imp = s.substr(start, end - start);
    for (int i = 0; i < indexes.size(); i = i + 2){
        string temp = medium(s, indexes[i], indexes[i+1]);
        string ans = "";
        cout << s[indexes[i] - 2] - '0' << endl;
        for (int j = 0; j < s[indexes[i] - 2] - '0'; j++){
            ans.append(temp);
        }
        replacement.push_back(ans);
    }


    

    

    // string ans = "";
    // if (start > 0){
    //     for (int i = 0; i < s[start - 2] - '0'; i++){
    //         ans.append(imp);
    //     }
    // }

    return imp;
}

string decodeString(string s){
    string ans;
    ans = medium(s, 0, s.size());
    return ans;
}


int main(){
    cout << decodeString("3[a2[c]]") << endl;
    return 0;
}