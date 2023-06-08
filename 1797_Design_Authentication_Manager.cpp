#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class AuthenticationManager {
public:
    int timeToLive;
    vector <int> ans;
    unordered_map <string, int> store;

    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        store[tokenId] = currentTime;
        ans.push_back(currentTime);
    }
    
    void renew(string tokenId, int currentTime) {
        if (ans[store[tokenId]] + timeToLive > currentTime) {
            ans.erase(ans.begin() + store[tokenId]);
            store[tokenId] = currentTime;
            ans.push_back(currentTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it = lower_bound(ans.begin(), ans.end(), currentTime - timeToLive);
        return (ans.end() - it);
    }
};

int main() {
    return 0;
}