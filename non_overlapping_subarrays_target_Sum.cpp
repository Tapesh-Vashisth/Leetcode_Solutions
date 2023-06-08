#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector <pair <int, int>>& v, int x){
    int low = 0;
    int high = v.size() - 1;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (x <= v[mid].second){
            high = mid - 1;
        }else{  
            low = mid + 1;
        }
    }

    return min(low, high);
}

int minSumOfLengths(vector<int>& arr, int target){
    const int m = (~(1 << 31));
    int back = 0;
    int sum = 0;
    int ans = m;
    vector <int> mins = {m};
    vector <pair<int, int>> store;
    int decide = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if (sum > target){
            while (sum > target){
                sum -= arr[back];
                back++;
            }
        }

        if (sum == target){
            store.push_back({back, i});
            if (i - back + 1 < mins[mins.size() - 1]){
                mins.push_back(i - back + 1);
            }else{
                mins.push_back(mins[mins.size() - 1]);
            }
            
            int pos = 0;
            if (store.size() != 0){
                int decider = 0;
                int pos = lower_bound(store, back);
                if (pos != -1){
                    decider = 1;
                }
                if (decider){
                    decide = 1;
                    int grab = mins[pos + 1] + (i - back + 1);

                    if (grab < ans){
                        ans = grab;
                    }
                }
            }


        }
    }

    while (back < arr.size() && sum >= target){
        if (sum > target){
            while (sum < target){
                sum -= arr[back];
                back++;
            }
        }

        if (sum == target){
            store.push_back({back, arr.size() - 1});
            if (arr.size() - 1 - back + 1 < mins[mins.size() - 1]){
                mins.push_back(arr.size() - 1 - back + 1);
            }else{
                mins.push_back(mins[mins.size() - 1]);
            }
            
            int pos = 0;
            if (store.size() != 0){
                int decider = 0;
                int pos = lower_bound(store, back);
                if (pos != -1){
                    decider = 1;
                }

                if (decider){
                    decide = 1;
                    int grab = mins[pos + 1] + (arr.size() - 1 - back + 1);

                    if (grab < ans){
                        ans = grab;
                    }
                }
            }
            sum -= arr[back];
            back++;
        }
    }


    if (decide){
        return ans;
    }else{
        return -1;
    }
}

int main(){
    vector <int> v = {1,2,2,3,2,6,7,2,1,4,8};
    cout << minSumOfLengths(v, 5) << endl;
    return 0;
}