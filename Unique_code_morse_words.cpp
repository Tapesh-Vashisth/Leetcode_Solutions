#include <iostream>
#include <vector>
#include <set>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    set<string> s;
    vector <string> storage = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    for (int i = 0; i < words.size(); i++){
        string temp;
        for (char j: words[i]){
            temp.append(storage[j - 'a']);
        }
        s.insert(temp);
    }

    return s.size();
}

int main(){
    vector <string> v = {"a"};
    cout << uniqueMorseRepresentations(v) << endl;
    return 0;
}