#include <iostream>
#include <vector>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    vector <bool> cols(mat[0].size(), false);
    vector <bool> rows(mat.size(), false);

    int ans = 0;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                if (cols[j] == false && rows[i] == false) {
                    cols[j] = true;
                    rows[i] = true;

                    bool decider = false;
                    for (int k = i + 1; k < mat.size(); k++) {
                        if (mat[k][j] == 1) {
                            decider = true;
                            break;
                        }
                    }

                    for (int k = j + 1; k < mat[i].size(); k++) {
                        if (mat[i][k] == 1) {
                            decider = true;
                            break;
                        }
                    }


                    if (decider == false) {
                        ans++;
                    }
                } else {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
    }        

    return ans;
}

int main() {
    return 0;
}