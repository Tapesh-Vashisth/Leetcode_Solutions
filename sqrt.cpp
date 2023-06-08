#include <iostream>
using namespace std;

int mySqrt(int x){
    int mover = x;
    int prevmover = x/2;
    while (prevmover < mover){
        if (prevmover*prevmover > x){
            mover = prevmover;
            prevmover = prevmover/2;
        }else if(prevmover*prevmover < x){
            int mid = (mover + prevmover)/2;
            if (mid == prevmover){
                return prevmover;
            }
            if (mid * mid > x){
                mover = mid;
            }else if(mid * mid < x){
                prevmover = mid;
            }else{
                return mid;
            }
        }else{
            return prevmover;
        }
    }

    return prevmover;
}

int main(){

    cout << mySqrt(101) << endl;
    return 0;
}