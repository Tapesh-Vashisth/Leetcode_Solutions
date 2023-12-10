#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int binarySearch(vector <int> & arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

unordered_map <int, unordered_map <int, bool>> memory;

bool helper(vector <int>& stones, int prev_jump, int present){
    if (memory.find(present) != memory.end() && memory[present].find(prev_jump) != memory[present].end()){
        return memory[present][prev_jump];
    }

    if (present == stones[stones.size() - 1]){
        return true;
    }else if(present > stones[stones.size() - 1]){
        return false;
    }else{
        if (binarySearch(stones, 0, stones.size() - 1, present) != -1){

            bool decider = false;
            for (int i = -1; i <= 1; i++){
                if (prev_jump + i > 0){
                    bool temp = helper(stones, prev_jump + i, present + prev_jump + i);
                    if (temp == true){
                        decider = true;
                        break;
                    }
                }
            }

            if (memory.find(present) == memory.end()){
                unordered_map <int, bool> temp;
                temp[prev_jump] = decider;
                memory[present] = temp;
            }else{
                memory[present].insert({prev_jump, decider});
            }

            return decider;
        }else{
            return false;
        }

    }
}

bool canCross(vector <int>& stones){
    memory.clear();
    bool ans = helper(stones, 0, 0);
    return ans;
}

int main(){
    return 0;
}