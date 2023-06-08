#include <iostream>
#include <cmath>
using namespace std;

int last_one(long x){
    int shift = 0;
    int count = 0;
    int last_one = 0;
    while (count < 32){
        if (((x >> shift) & 1) != 0){
            last_one = count;
        }
        count++;
        shift++;
    }

    cout << last_one << endl;

    return last_one;
}

int logi(int x){
    int count = 0;
    while (x){
        count++;
        x = x/2;
    }

    return count;
}

int consecutive_ones(int x){
    if (x == 0){
        return 0;
    }else{
        long long decider = 1;
        long long ans = 0;
        for (int i = 0; i < x; i++){
            ans += decider;
            decider = decider * 2;
        }

        return ans;
    }
}

int rangeBitwiseAnd(int left, int right) {
    if (last_one(left) != last_one(right)){
        return 0;
    }else{
        int difference = right - left;
        int count = logi(difference);
        cout << count << endl;
        int decider = consecutive_ones(count);
        return (~decider) & right;
    }
}

int main(){
    cout << rangeBitwiseAnd(5, 6) << endl;
    return 0;
}