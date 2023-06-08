#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool comparator(int first, int second){
    return first > second;
}

int minSetSize(vector<int>& arr){
    unordered_map <int, int> counter;

    for (int i = 0; i < arr.size(); i++){
        counter.insert(pair <int, int> {arr[i], 0});
    }

    for (int i = 0; i < arr.size(); i++){
        counter[arr[i]]++;
    }

    unordered_map <int, int> :: iterator it = counter.begin();

    vector <int> holder;

    for (; it != counter.end(); it++){
        holder.push_back((*it).second);
    }

    sort(holder.begin(), holder.end(), comparator);

    int count = 0;
    int setsize = 0;
    for (int i = 0; i < holder.size(); i++){
        count += holder[i];
        setsize += 1;
        if (count > arr.size()/2){
            break;
        }
    }

    return setsize;
}

int main(){
    vector <int> v = {3,3,3,3};
    cout << minSetSize(v) << endl;
    return 0;
}