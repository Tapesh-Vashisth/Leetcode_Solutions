#include <iostream>
#include <algorithm>
using namespace std;

int maximumScore(int a, int b, int c){
    int sorted[] = {a, b, c};
    sort(sorted, sorted + 3);
    for (int i =0; i < 3; i++){
        cout << sorted[i] << " ";
    }
    cout << endl;
    int ans = 0;

    if (sorted[2] - sorted[0] >= sorted[1]){
        return sorted[0] + sorted[1];
    }else if(sorted[2] - sorted[0] < sorted[1]){
        ans = sorted[2] - sorted[1];
        sorted[2] = sorted[1];
        sorted[0] = sorted[0] - ans;
        int first = sorted[0]/2;
        int second = sorted[0] - first;
        ans += first + second;
        sorted[1] = sorted[1] - second;
        sorted[2] = sorted[2] - first;
        ans += min(sorted[1], sorted[2]);
    }
    return ans;
}

int main(){
    cout << maximumScore(4, 4, 6) << endl;
    return 0;
}