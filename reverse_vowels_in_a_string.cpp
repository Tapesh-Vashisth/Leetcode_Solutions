#include <iostream>
using namespace std;

bool isvowel(char x){
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
        return true;
    }

    return false;
}

string reverseVowels(string s){
    int low = 0;
    int high = s.size() - 1;
    while (low < high){
        if (!isvowel(s[low])){
            low++;
        }

        if (!isvowel(s[high])){
            high--;
        }

        if (isvowel(s[low]) && isvowel(s[high])){
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }

    return s;
}

int main(){
    return 0;
}