#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cstring>
#include <time.h>
#include <chrono>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ff second
#define ss first
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x));
#define sortall(x) sort(all(x))
#define tr(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const double pi = 3.141592653589793238;
const ll mod = 1e9+7;

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vpl arr(26);
    for(int i = 0; i < 26; i++) arr[i].second = i;
    // deb(s[1]-'a');
    for(int i = 0; i<n; i++) arr[s[i]-'a'].first++, arr[s[i]-'a'].second = s[i] - 'a';
    // for(auto &i : arr) cout<<i.first << " " << i.second << endl;
    // vl temp3(26, 0);
    // for(auto &i : arr) temp3[i.second] = i.first;
    // for(auto &i : temp3) cout<<i<<" ";
    // cout<<endl;
    int ans1 = -1, ans2 = 0;
    sort(all(arr));
    reverse(all(arr));
    for(int i = 1; i<=26; i++) {
        if(n%i) continue;
        ll sum = 0;
        for(int j = 0; j < i; j++) sum += min(n/i, arr[j].first);
        if(sum > ans1) {
            ans1 = sum;
            ans2 = i;
        }
    }
    cout<<n-ans1<<endl;
    // deb(ans2); 
    vl temp(26, 0);
    vl temp2(26, 0);
    for(int i = 0; i < ans2; i++) {
        if(arr[i].first < n/ans2) temp2[arr[i].second] = n/ans2 - arr[i].first;
        arr[i].first = max(n/ans2, arr[i].first) - n / ans2;
    }
    for(auto &i : arr) temp[i.second] = i.first;
    // for(auto &i : temp) cout<<i<<" ";
    // cout<<endl;
    // for(auto &i : temp2) cout<<i<<" ";
    // cout<<endl;
    int i = 0;
    int j = 0;
    string ans = s;
    while(i<n && j<26) {
        if(temp2[j]==0) {
            j++;
            continue;
        }
        int x = s[i] - 'a';
        if(temp[x]<=0) {
            i++;
            continue;
        } else {
            // cout<<i<<" "<<j<<" "<<(char)(97+j)<<endl;
            ans[i] = (char)(97+j);
            i++;
            temp2[j]--;
            temp[x]--;
        }
    }
    cout<<ans<<endl;



}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}