#include <iostream>
using namespace std;

string breakPalindrome(string palindrome){
    int breakpoint;
    if (palindrome.size()%2 == 0){
        breakpoint = palindrome.size()/2;
    }else{
        breakpoint = palindrome.size()/2 + 1;
    }

    bool checker = false;
    for (int i = 0; i < breakpoint; i++){
        if (palindrome[i] != 'a'){
            palindrome[i] = 'a';
            checker = true;
            break;
        }
    }

    if (checker){
        return palindrome;
    }else{
        return "";
    }
}

int main(){
    return 0;
}