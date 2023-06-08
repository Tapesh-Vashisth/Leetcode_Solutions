#include <iostream>
#include <list>
using namespace std;


int counter(string & check, char val, int index){
    int hold = 0;
    while (index < check.size() && check[index] == val){
        hold++;
        index++;
    }

    return hold;
}

string countAndSay(int n) {
    string hold = "1";
    for (int i = 2; i <= n; i++){
        string updated = "";
        // internal checking 
        for (int j = 0; j < hold.size();){
            int decider = counter(hold, hold[j], j);
            updated.append(to_string(decider));
            updated.push_back(hold[j]);
            j += decider;
        }

        hold = updated;
    }

    return hold;
}

int main(){
    return 0;
}