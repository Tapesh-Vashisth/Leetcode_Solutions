#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height){
    int front = 0;
    int end = height.size() - 1;
    int max = 0;
    while (front < end){
        int h = (height[front] > height[end] ? height[end]: height[front]);
        int area = (end - front) * h;
        if (area > max){
            max = area;
        }

        if (height[front] > height[end]){
            end--;
        }else{
            front++;
        }
    }

    return max;
}

int main(){
    vector <int> v = {1,1};
    cout << maxArea(v) << endl;
    return 0;
}