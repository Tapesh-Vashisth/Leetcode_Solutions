#include <iostream>
#include <vector>
using namespace std;

int power(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++){
        ans *= a;
    }

    return ans;
}

// vector<string> letterCombinations(string digits){
//     vector <string> result;
//     int decider = digits.size();
//     int values_of_letters[8] = {3, 3, 3, 3, 3, 4, 3, 4};
//     int number_of_letters[8] = {0, 3, 6, 9, 12, 15, 19, 22};
//     int counter = 1;
//     for (int i = 0; i < decider; i++){
//         counter = counter * values_of_letters[digits[i] - '0' - 2];
//     }

//     int jump = counter;


//     result.resize(counter);
//     for (int i = 0; i < decider; i++){
//         char controller = 'a' + number_of_letters[digits[i] - '0' - 2] - 1;
//         int index = 0;
//         jump = jump/values_of_letters[digits[i] - '0' - 2];
//         int count = 0;
//         char controller_temp = controller;
//         for (int j = 0; j < counter; j++){
//             if (index%jump == 0){
//                 if (count%values_of_letters[digits[i] - '0' - 2] == 0){
//                     controller_temp = controller;
//                 }
//                 count++;
//                 controller_temp++;
//                 result[j].push_back(controller_temp);
//             }else{
//                 result[j].push_back(controller_temp);
//             }
//             index++;
//         }
//     }

//     return result;
// }

vector <string> helper(string digits, vector <string>& v){
    if (digits.size() == 0){
        return vector <string> {""};
    }else{
        int decider = (digits[0] - '0') - 2;
        vector <string> ans;
        for (int i = 0; i < v[decider].size(); i++){
            vector <string> temp = helper(digits.substr(1), v);
            for (int j = 0; j < temp.size(); j++){
                temp[j].push_back(v[decider][i]);
            }

            ans.insert(ans.begin(), temp.begin(), temp.end());
        }

        return ans;
    }
}

vector<string> letterCombinations(string digits) {
    vector <string> data = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return helper(digits, data);
}

int main(){
    vector <string> ans;
    ans = letterCombinations("23");
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}