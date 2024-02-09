#include <iostream>
#include <unordered_map>
using namespace std;


int firstUniqChar(string s){
    unordered_map <char, int> storage;
    for (int i = 0; i < s.size(); i++){
        storage[s[i]] = 0;    
    }

    for (int i = 0; i < s.size(); i++){
        storage[s[i]]++;    
    }

    for (int i = 0; i <= s.size(); i++){
        if (storage[s[i]] == 1){
            return i;
        }
    }

    return -1;
}


int main() {
    return 0;
}