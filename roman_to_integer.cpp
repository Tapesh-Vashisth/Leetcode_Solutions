#include <iostream>
using namespace std;

int value_equi(char x){
    if (x == 'I'){
        return 1;
    }else if (x == 'V'){
        return 5;
    }else if (x == 'X'){
        return 10;
    }else if (x == 'L'){
        return 50;
    }else if (x == 'C'){
        return 100;
    }else if (x == 'D'){
        return 500;
    }else if (x == 'M'){
        return 1000;
    }else{
        return 0;
    }
}

int romanToInt(string s){
    int ans = 0;
    int now = 0;
    int then = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[now] == 'V' && s[then] == 'I'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else if(s[now] == 'X' && s[then] == 'I'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else if(s[now] == 'L' && s[then] == 'X'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else if(s[now] == 'C' && s[then] == 'X'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else if(s[now] == 'D' && s[then] == 'C'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else if(s[now] == 'M' && s[then] == 'C'){
            ans = ans + value_equi(s[now]) - 2*value_equi(s[then]);
        }else{
            ans = ans + value_equi(s[i]);
        }
        then = now;
        now++;    
    }
    return ans;
}

int main(){
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;

    return 0;
}