#include <iostream>
#include <algorithm>
#include <cwctype>
using namespace std;

bool isPalindrome(string s){
    int low = 0;
    int high = s.size() - 1;
    while (low < high){
        if (!iswalnum(s[low])){
            low++;
            continue;
        }

        if (!iswalnum(s[high])){
            high--;
            continue;
        }

        if (tolower(s[low]) != tolower(s[high])){
            return false;
        }else{
            low++;
            high--;
        }
    }

    return true;
}

int main(){
    cout << isPalindrome(" ") << endl;
    return 0;
}