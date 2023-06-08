#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s){
    int in = 0;
    auto it_front = s.begin();
    auto it_back = s.begin();
    while (it_front != s.end()){
        if (*it_front == ' ' && in == 1){
            in = 0;
            reverse(it_back, it_front);
            it_back = it_front;
        }else if(*it_front == ' '){
            it_front++;
            it_back++;
        }else if(*it_front != ' ' && in == 0){
            in = 1;
        }else if(*it_front != ' '){
            it_front++;
        }
    }

    reverse(it_back, it_front);

    return s;
}

int main(){
    cout << reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}