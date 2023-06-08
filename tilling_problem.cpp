#include <iostream>
using namespace std;

int arr[150];

int tilling(int n){
    if (n == 0){
        return 1;
    }else if(n < 0){
        return 0;
    }else{
        if (arr[n] != -1){
            return arr[n];
        }
        int count = 0;
        count += tilling(n - 1);
        count += tilling(n - 4);
        arr[n] = count;
        return count;
    }
}

int tilling_d(int n){
    int array[150];
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 2;
    for (int i = 5; i < 100; i++){
        array[i] = array[i - 4] + array[i - 1];
    }

    return array[n];
}

int main(){
    for (int i = 0; i < 150; i++){
        arr[i] = -1;
    }
    int n;
    cin >> n;
    cout << tilling_d(n) << endl;
    return 0;
}