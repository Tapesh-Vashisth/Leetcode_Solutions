#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> numsSameConsecDiff(int n, int k){
    vector <int> ans(10);
    iota(ans.begin(), ans.end(), 0);
    int decider = 1;
    for (int i = 0; i < n - 1; i++){
        vector <int> holder = ans;
        for (int j = 0; j < ans.size(); j++){
            int digit = (ans[j]/decider)%10;
            cout << digit << endl;
            int add1 = digit + k;
            if (add1 <= 9 && k != 0){
                holder.push_back(add1*decider*10 + ans[j]);
            }
            int add2 = digit - k;
            if (i != n - 2){
                if (add2 >= 0){
                    holder.push_back(add2*decider*10 + ans[j]);
                }
            }else{
                if (add2 > 0){
                    holder.push_back(add2*decider*10 + ans[j]);
                }
            }
        }
        decider = decider * 10;

        vector <int> :: iterator it = holder.begin();

        for (int i = 0; i < ans.size(); i++){
            holder.erase(it);
        }

        for (int i = 0; i < holder.size(); i++){
            cout << holder[i] << " ";
        }

        cout << endl;

        ans = holder;
    }

    return ans;
}

int main(){
    vector <int> ans;
    ans = numsSameConsecDiff(2, 0);
    return 0;
}