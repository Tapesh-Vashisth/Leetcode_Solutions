#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }else{
            int second = 0;
            for (int i = 0; i < haystack.size(); i++){
                if (haystack[i] == needle[second]){
                    second++;
                }else if(second > 0){
                    i = i - second;
                    second = 0;
                }

                if (second == needle.size()){
                    return i - needle.size() + 1;
                }
            }
            return -1;
        }
}

int main(){
    cout << strStr("mississippi", "pi") << endl;
    return 0;
}