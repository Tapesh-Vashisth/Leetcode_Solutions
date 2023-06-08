#include <iostream>
#include <vector>
using namespace std;

vector <pair <float, int>> storage;  

float min_money(vector <pair <int, float>>& xd, int amount){
    if (amount == 0){
        return 0;
    }else if(amount < 0){
        return -1;
    }else{
        for (int i = 0; i < storage.size(); i++){
            if (amount == storage[i].second){
                return storage[i].first;
            }
        }

        float min = 100000;

        for (int i = 0; i < xd.size(); i++){
            float temp = min_money(xd, amount - xd[i].first);
            if (temp == -1){
                ;
            }else{
                temp = temp + xd[i].second;
                if (temp < min){
                    min = temp;
                }
            }
        }

        storage.push_back({min, amount});
        return min;
    }
}

int main(){
    vector <pair <int, float>> v;
    int offers;
    float first;
    cin >> first >> offers;
    v.push_back({1, first});
    for (int i = 0; i < offers; i++){
        float temp_cost;
        int temp_count;
        cin >> temp_count >> temp_cost;
        v.push_back({temp_count, temp_cost});
    }

    // for (int i = 0; i < v.size(); i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    int test;
    cin >> test;
    float ans = min_money(v, test);

    cout << ans << endl;
}