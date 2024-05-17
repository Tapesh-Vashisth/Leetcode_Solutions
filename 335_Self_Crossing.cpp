#include <iostream>
#include <vector>
using namespace std;

bool isSelfCrossing(vector<int>& distance) {
    vector <pair <long long, long long>> lines;

    long long x = 0;
    long long y = 0;
    lines.push_back({x, y});
    for (int i = 0; i < distance.size(); i++) {
        if (i % 4 == 0) {
            y += distance[i];
        } else if (i % 4 == 1) {
            x -= distance[i];
        } else if (i % 4 == 2) {
            y -= distance[i];
        } else {
            x += distance[i];
        }
        lines.push_back({x, y});
        int numLines = i + 1;
        // i - 3 check
        if (lines.size() >= 5) {
            if (lines[numLines].second == lines[numLines - 1].second) {
                if (abs(lines[numLines].first - lines[numLines - 1].first) >= abs(lines[numLines - 3].first - lines[numLines - 1].first) && abs(lines[numLines - 4].second - lines[numLines - 3].second) >= abs(lines[numLines].second - lines[numLines - 3].second)) {
                    return true;
                }
            } else {
                if (abs(lines[numLines].second - lines[numLines - 1].second) >= abs(lines[numLines - 3].second - lines[numLines - 1].second) && abs(lines[numLines - 4].first - lines[numLines - 3].first) >= abs(lines[numLines].first - lines[numLines - 3].first)) {
                    return true;
                }
            }
        }

        // i - 5 check
        if (lines.size() >= 7) {
            if (lines[numLines].second == lines[numLines - 1].second) {
                if ((lines[numLines].first - lines[numLines - 6].first) * (lines[numLines - 1].first - lines[numLines - 6].first) <= 0 && (lines[numLines - 5].second - lines[numLines].second) * (lines[numLines - 6].second - lines[numLines].second) <= 0) {
                    return true;
                }
            } else {
                if ((lines[numLines].second - lines[numLines - 6].second) * (lines[numLines - 1].second - lines[numLines - 6].second) <= 0 && (lines[numLines - 5].first - lines[numLines].first) * (lines[numLines - 6].first - lines[numLines].first) <= 0) {
                    return true;
                }
            }
        }

        // i - 4 check 
        if (lines.size() >= 6) {
            if (lines[numLines].second == lines[numLines - 1].second) {
                if (lines[numLines].second == lines[numLines - 5].second && abs(lines[numLines].first - lines[numLines - 4].first) <= abs(lines[numLines - 5].first - lines[numLines - 4].first)) {
                    return true;
                }
            } else {
                if (lines[numLines].first == lines[numLines - 5].first && abs(lines[numLines].second - lines[numLines - 4].second) <= abs(lines[numLines - 5].second - lines[numLines - 4].second)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    return 0;
}