#include <iostream>
using namespace std;

int titleToNumber(string columnTitle) {
    int ans = 0;
    int pw = 1;
    for (int i = 0; i < columnTitle.size(); i++){
        int hold = columnTitle[i] - 'A' + 1;
        ans += pw * hold;
        pw *= 26;
    }        


    return ans;
}


int main(){
    return 0;
}