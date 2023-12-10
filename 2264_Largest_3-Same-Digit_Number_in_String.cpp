#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string largestGoodInteger(string num) {
    string ans = "";
    int ansnum = 0;

    for (int i = 0; i < num.size(); i++) {
        int index = i;

        int counter = 0;
        string temp = "";
        while (index + counter < num.size() && counter < 3) {
            temp.push_back(num[index + counter]);
            counter++;
        }

        set <char> store;
        
        for (int j = 0; j < temp.size(); j++) {
            store.insert(temp[j]);
        }

        if (store.size() == 1 && temp.size() == 3) {
            int hold = stoi(temp);
            if (hold >= ansnum) {
                ansnum = hold;
                ans = temp;
            }
        }   
    }

    return ans;
}

int main() {
    return 0;
}