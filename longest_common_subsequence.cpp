#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> memory;

int helper(string first, int index1, string second, int index2){
    if (memory[index1][index2] != -1){
        return memory[index1][index2];
    }

    if (index1 >= first.size() || index2 > second.size()){
        return 0;
    }else{
        int ans;
        if (first[index1] == second[index2]){
            ans = 1 + helper(first, index1 + 1, second, index2 + 1);
        }else{
            ans = max(helper(first, index1, second, index2 + 1), max(helper(first, index1 + 1, second, index2), helper(first, index1 + 1, second, index2 + 1)));
        }

        memory[index1][index2] = ans;
        return ans;
    }
}

int longestCommonSubsequence(string text1, string text2){
    memory.resize(1001);
    fill(memory.begin(), memory.end(), vector <int> (1001, -1));
    int ans = helper(text1, 0, text2, 0);
    memory.clear();
    return ans;
}

int main(){

    return 0;
}