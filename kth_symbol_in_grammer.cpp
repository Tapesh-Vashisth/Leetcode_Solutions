#include <iostream>
#include <vector>
using namespace std;

int getithbit(long long x, int i){
    int bit = 1 << (i - 1);
    return (x & bit ? 1 : 0);
}

int kthGrammar(int n, int k){
    vector <int> xd;
    xd.clear();
    long long decider = 0;
    if (n%2 == 0){
        decider = 1;
    }     

    cout << decider << endl;   

    int count = 1;
    while (count < k){
        decider = (decider | (~decider << count)); 
        count = count * 2;
        cout << decider << endl;
    }
    int ans = getithbit(decider, k);
    return ans;
}


int main(){
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k);
    return 0;
}