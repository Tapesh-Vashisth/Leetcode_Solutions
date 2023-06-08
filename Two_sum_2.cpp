#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector <int> result;
    int front = 0;
    int end = numbers.size() - 1;
    while (front < end){
        if (numbers[front] + numbers[end] == target){
            result.push_back(front + 1);
            result.push_back(end + 1);
            break;
        }else if(numbers[front] + numbers[end] > target){
            end--;
        }else{
            front++;
        }
    }

    return result;
}

int main(){
    vector <int> v{2,3,4};
    vector <int> r = twoSum(v, 6);
    for (int i = 0; i < r.size(); i++){
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}