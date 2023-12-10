#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;


class monoTonicQueue {
    stack <pair <pair <int, int>, int>> first;
    stack <pair <pair <int, int>, int>> second;

    public:
        monoTonicQueue() {
            ;
        }    

        void pushFirst(int x) {
            int mx = max(x, first.empty() ? INT32_MIN: first.top().first.second);
            int mn = min(x, first.empty() ? INT32_MAX: first.top().first.first);

            first.push({{mn, mx}, x});
        }  

        void pushSecond(int x) {
            int mx = max(x, second.empty() ? INT32_MIN: second.top().first.second);
            int mn = min(x, second.empty() ? INT32_MAX: second.top().first.first);

            second.push({{mn, mx}, x});
        }  

        pair <int, int> minMax() {
            pair <int, int> ret = {INT32_MAX, INT32_MIN};
            ret.first = min(ret.first, min(first.empty() ? INT32_MAX : first.top().first.first, second.empty() ? INT32_MAX : second.top().first.first));
            ret.second = max(ret.second, max(first.empty() ? INT32_MIN : first.top().first.second, second.empty() ? INT32_MIN : second.top().first.second));

            return ret;
        }

        void pop() {
            if (second.empty()) {
                while (!first.empty()) {
                    pushSecond(first.top().second);
                    first.pop();
                }
            }

            second.pop();
        }

        int size() {
            return first.size() + second.size();
        }
};

long long continuousSubarrays(vector<int>& nums) {
    monoTonicQueue store;
    int low = 0;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        store.pushFirst(nums[i]);

        pair <int, int> mnmx = store.minMax();
        int mn = mnmx.first;
        int mx = mnmx.second;
        while (abs(mn - mx) > 2) {
            store.pop();

            mnmx = store.minMax();
            mn = mnmx.first;
            mx = mnmx.second;
        }


        ans += store.size();
    }

    return ans;
}

int main() {
    return 0;
}