#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s){
    if (s.size() == 0){
        return 0;
    }else{
        int front = 0;
        int end = 0;
        int maxlength = 1;
        int length = 1;
        for (int i = 1; i < s.size(); i++){
            int decider = 0;
            for (int j = front; j <= end; j++){
                if (s[i] == s[j]){
                    front = j + 1;
                    end = j + 1;
                    i = j + 1;
                    length = 1;
                    decider = 1;
                    break;
                }
            }
            if (decider == 0){
                length++;
                end++;
            }else{

            }    
            if (length > maxlength){
                maxlength = length;
            }
        }
        if (length > maxlength){
            maxlength = length;
        }
        return maxlength;
    }
}

int main(){
    string s = "tapeshtap";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}