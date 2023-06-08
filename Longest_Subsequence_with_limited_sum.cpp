#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());

    vector <int> ans = {0};
    for (int i = 0; i < nums.size(); i++){
        ans.push_back(ans[ans.size() - 1] + nums[i]);
    }

    vector <int> answers;
    for (int i = 0; i < queries.size(); i++){
        answers.push_back(upper_bound(ans.begin(), ans.end(), queries[i]) - ans.begin() - 1);
    }

    return answers;
}


int main(){
    vector <int> v = {1, 1, 1, 2, 2};
    int value = upper_bound(v.begin(), v.end(), 2) - v.begin();
    cout << value << endl;
    return 0;
}