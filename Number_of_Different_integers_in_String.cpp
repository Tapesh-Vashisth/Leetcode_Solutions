#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numDifferentIntegers(string word){
    int i = 0;
    int count = 0;
    vector <int> v;
    while (i < word.size()){
        if (word[i] >= '0' && word[i] <= '9'){
            int temp = 0;
            int multi = 10;
            while (word[i] >= '0' && word[i] <= '9'){
                temp = temp*multi + (word[i] - '0');
                
                i++;
            }
            v.push_back(temp);
        }
        i++;
    }
    unordered_set <int> s;
    for (auto x: v){
        s.insert(x);
    }


    return s.size();
}

int main(){
    cout << numDifferentIntegers("leet1234code234") << endl;
    return 0;
}