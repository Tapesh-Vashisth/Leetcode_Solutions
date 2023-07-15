#include <iostream>
#include <vector>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int mx = 1;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int current = 0;
            for (int k = 0; k < points.size(); k++) {
                if (k != i && k != j) {
                    if ((points[k][0] - points[j][0]) * (points[j][1] - points[i][1]) == (points[k][1] - points[j][1]) * (points[j][0] - points[i][0])) {
                        current++;
                    }
                }
            }

            mx = max(mx, current + 2);
        }
    }        


    return mx;
}


int main() {
    return 0;
}