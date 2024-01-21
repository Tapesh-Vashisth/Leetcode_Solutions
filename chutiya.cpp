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
    int m, n;
    cin>>m>>n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin>>arr[i][j];
    }
    int srx, sry;
    cin>>srx>>sry;
    int desx,desy;
    cin>>desx>>desy;
    vector<int> mv(2);
    for(auto &i : mv) cin>>i;
    vector<pair<int, int>> mvorder;
    mvorder.pb({mv[0], mv[1]});
    mvorder.pb({mv[1], -1*mv[0]});
    mvorder.pb({-1*mv[1], mv[0]});
    mvorder.pb({mv[0], -1*mv[1]});

    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> store;
    store.push({srx, sry});
    visited[srx][sry] = 1;
    int ans = 0;
    while(store.size()) {
        ans++;
        int sz = store.size();
        for(int i = 0; i < sz; i++) {
            int tx = store.front().first, ty = store.front().second;
            store.pop();
            for(int j = 0; j < 4; j++) {
                int nx = tx + mvorder[j].first, ny = ty + mvorder[j].second;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] == 1 || arr[nx][ny] == 1) {
                    continue;
                }
                if(nx == desx && ny == desy) {
                    cout<<ans<<endl;
                    return;
                }
                visited[nx][ny] = 1;
                store.push({nx, ny});
            }
        }
    }
    cout<<"-1\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}