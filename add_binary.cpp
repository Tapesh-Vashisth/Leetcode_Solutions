#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b){
    string result; 
    string :: iterator it1 = a.begin();
    string :: iterator it2 = b.begin();


    int carry = 0;
    while (it1 != a.end() && it2 != b.end()){
        int add = (carry + (*it1 - '0') + (*it2 - '0'))%2;
        carry = (carry + (*it1 - '0') + (*it2 - '0'))/2;
        result.push_back(add);
        it1++;
        it2++;
    }

    while (it1 != a.end()){
        int add = (carry + (*it1 - '0'))%2;
        carry = (carry + (*it1 - '0'))/2;
        result.push_back(add);
        it1++;
    }

    while (it2 != b.end()){
        int add = (carry + (*it2 - '0'))%2;
        carry = (carry + (*it2 - '0'))/2;
        result.push_back(add);
        it2++;
    }

    if (carry == 1){
        result.push_back(1);
    }

    return result;
}

int main(){
    return 0;
}