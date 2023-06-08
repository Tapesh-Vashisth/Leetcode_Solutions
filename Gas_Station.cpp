#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector <int> diff;

    for (int i = 0; i < gas.size(); i++) {
        diff.push_back(gas[i] - cost[i]);
    }   

    for (int i = 0; i < diff.size(); i++) {
        cout << diff[i] << " ";
    }
    cout << endl;

    vector <int> change;

    if ((diff[0] < 0 && diff[diff.size() - 1] >= 0) || (diff[0] >= 0 && diff[diff.size() - 1] < 0)) {
        change.push_back(0);
    }

    for (int i = 1; i < diff.size(); i++) {
        if ((diff[i] < 0 && diff[i - 1] >= 0) || (diff[i] >= 0 && diff[i - 1] < 0)) {
            change.push_back(i);
        }
    }

    for (int i = 0; i < change.size(); i++) {
        cout << change[i] << " ";
    }
    cout << endl;

    int start = change[0];

    vector <int> contisum;
    int minimum= INT_MAX;
    pair<int,pair<int,int>>p;
    int next_ind ;
    for(int i =0;i <change.size();i++)
    {
        if(i==change.size()-1)next_ind=change[0];
        else next_ind = change[i+1];
        int sum=0;
        for(int j=change[i];j!=next_ind;j=(j+1)%diff.size())
        {
            sum+=diff[j];
        }
        contisum.push_back(sum);
    }
    for(auto it : contisum)
    cout<<it<<" ";

    int minindex = 0;
    int maxmountain = INT_MAX;
    for (int i = 0; i < contisum.size(); i++) {
        maxmountain = min(contisum[i], maxmountain);
        minindex = i;
    }

    start = (minindex + 1)%contisum.size();

    int actualStart = start;
    int profit = 0;
    while (start != minindex) {
        profit += contisum[start];
        if (profit < 0) {
            profit = 0;
            actualStart = (start + 1)%contisum.size();
        }
        start = (start + 1)%contisum.size();
    }

    cout << actualStart << endl;

    return 0;
}

int main() {
    vector <int> gas = {1,2,3,5,1,6,7,8,9,1,2,10};
    vector <int> cost = {0,0,0,10,2,12,0,0,0,2,4,0};
    canCompleteCircuit(gas, cost);
    return 0;
}