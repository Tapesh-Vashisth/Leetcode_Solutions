#include <iostream>
#include <vector>
using namespace std;

class ATM {
public:
    vector <int> denominations;
    vector <int> atm;

    ATM() {
        denominations = {20, 50, 100, 200, 500};
        atm = {0, 0, 0, 0, 0};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            atm[i] += banknotesCount[i];
        }
    }

    bool helper(int amount, int index) {
        if (index < 0 && amount == 0) {
            return 1;
        } else if (index < 0 && amount > 0) {
            return 0;
        }

        int notesRequired = amount / denominations[index];

        int available = min(notesRequired, atm[index]);

        if (helper(amount - denominations[index] * available, index - 1)) {
            atm[index] -= available;

            return true;
        } else {
            return false;
        }
    }
    
    vector<int> withdraw(int amount) {
        vector <int> temp = atm;
        if (helper(amount, 4)) {
            vector <int> ans;
            for (int i = 0; i < temp.size(); i++) {
                ans.push_back(temp[i] - atm[i]);
            } 

            return ans;
        } else {
            return {-1};
        }
    }
};

int main() {
    return 0;
}