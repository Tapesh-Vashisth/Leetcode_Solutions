#include <iostream>
using namespace std;

string getHint(string secret, string guess){
    string ans;
    int x = 0;
    int y = 0;
    string remaining;
    string guess_r;
    for (int i = 0; i < secret.size(); i++){
        if (secret[i] == guess[i]){
            x++;
        }else{
            remaining.push_back(secret[i]);
            guess_r.push_back(guess[i]);
        }
    }

    string buffer;
    while (x){
        buffer.push_back(x%10 + '0');
        x = x/10;
    }
    for (int i = buffer.size() - 1; i >= 0; i--){
        ans.push_back(buffer[i]);
    }
    buffer.clear();
    
    ans.push_back('A');

    int hash[10] = {0};

    for (int i = 0; i < remaining.size(); i++){
        hash[remaining[i] - '0']++;        
    }

    for (int i = 0; i < guess_r.size(); i++){
        if (hash[guess_r[i] - '0'] > 0){
            y++;
            hash[guess_r[i] - '0']--;
        }
    }

    while (y){
        buffer.push_back(y%10 + '0');
        y = y/10;
    }
    for (int i = buffer.size() - 1; i >= 0; i--){
        ans.push_back(buffer[i]);
    }
    buffer.clear();

    ans.push_back('B');

    return ans;

}

int main(){
    cout << getHint("1123", "0111") << endl;
    return 0;
}