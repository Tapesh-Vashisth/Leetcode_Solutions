#include <iostream>
using namespace std;

bool checkIfPangram(string sentence){
    int hash[26] = {0};
    for (int i = 0; i < sentence.size(); i++){
        hash[sentence[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        if (hash[i] == 0){
            return false;
        }
    }

    return true;
}

int main(){
    return 0;
}