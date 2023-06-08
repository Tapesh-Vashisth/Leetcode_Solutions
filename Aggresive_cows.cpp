#include <iostream>
#include <set>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        set <int> store;
        int N, C; 
        cin >> N >> C; 
        for (int i = 0; i < N; i++){
            int x;
            cin >> x;
            store.insert(x);
        }
        set <int> :: iterator it = store.begin();
        for (; it != store.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        
        

        while (C > 0){

            C--;
        }
    }
    return 0;
}