#include <iostream>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int counter = 0;
    int prev = 0;
    vector <string> ans;
    int realLen = 0;
    for (int i = 0; i < words.size(); i++) {
        counter += words[i].size();
        realLen += words[i].size();
        if (counter > maxWidth) {
            realLen -= words[i].size();
            int spaces = i - prev - 1;
            int spaceLength = maxWidth - realLen;

            string hold = "";
            if (spaces == 0) {
                hold.append(words[prev]);
                
                for (int k = 0; k < spaceLength; k++) {
                    hold.push_back(' ');
                }
            } else {
                int ordinary = spaceLength/spaces;
                int extra = spaceLength % spaces;

                for (int j = prev; j < i - 1; j++) {
                    hold.append(words[j]);
                    int space = ordinary;
                    if (extra) {
                        space++;
                        extra--;
                    }

                    for (int k = 0; k < space; k++) {
                        hold.push_back(' ');
                    }
                }

                hold.append(words[i - 1]);
            }

            ans.push_back(hold);

            prev = i;
            counter = words[i].size() + 1;
            realLen = words[i].size();
        } else {
            counter += 1;
        }
    }

    int spaces = words.size() - prev - 1;
    int spaceLength = maxWidth - realLen;

    string hold = "";
    if (spaces == 0) {
        hold.append(words[prev]);
        
        for (int k = 0; k < spaceLength; k++) {
            hold.push_back(' ');
        }
    } else {
        for (int j = prev; j < words.size() - 1; j++) {
            hold.append(words[j]);
            hold.push_back(' ');
        }

        hold.append(words[words.size() - 1]);

        for (int k = hold.size(); k < maxWidth; k++) {
            hold.push_back(' ');
        }
    }

    ans.push_back(hold);

    return ans;
}

int main() {
    return 0;
}