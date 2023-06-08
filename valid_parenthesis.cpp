#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s){
    stack <char> storage;
    for (int i = 0; i < s.length(); i++){
        if (storage.empty() && (s[i] == '}' || s[i] == ')' ||s[i] == ']')){
            return false;
        }else if(s[i] == '{' || s[i] == '(' ||s[i] == '['){
            storage.push(s[i]);
        }else if(s[i] == '}' || s[i] == ')' ||s[i] == ']'){
            if (storage.top() == '{' && s[i] == '}'){
                storage.pop();
            }else if(storage.top() == '(' && s[i] == ')'){
                storage.pop();
            }else if(storage.top() == '[' && s[i] == ']'){
                storage.pop();
            }else{
                return false;
            }
        }
    }

    if (storage.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s;
    cout << "enter the expression: ";
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}