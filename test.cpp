#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define x 2;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;



long long mpow(long long n, long long p, long long m) {
	if(!p) return 1; 
	else if(p & 1) return ((__int128)n * mpow(n, p-1, m)) % m;
	else {
		long long v = mpow(n, p/2, m); 
		return (v*v) % m;
	}
}

bool isprime(long long n){
	set <int> ans;
	if(n<2) return false;
	for(long long i=2;i<1000000;++i) if(n%i==0) return false;
	long long i = rand()%(n-1)+1;
	if(mpow(i,n-1,n)!=1) return false;
	return true;
}

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
	cout << "hi" << endl;
	vector <vector <pair <int, int>>> graph(n + 2);
	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
	}
	
	priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> gp;
	
	vector <int> dists(n + 2, 1000000);
	vector <int> parents(n + 2, 0);
	dists[1] = 0;
	gp.push({0, 1});
	
	
	while (!gp.empty()) {
		pair <int, int> hold = gp.top();
		gp.pop();
		
		for (int i = 0; i < graph[hold.second].size(); i++) {
			if (hold.first + graph[hold.second][i].second < dists[graph[hold.second][i].first]) {
				parents[graph[hold.second][i].first] = hold.second;
				dists[graph[hold.second][i].first] = hold.first + graph[hold.second][i].second;
				gp.push({hold.first + graph[hold.second][i].second, graph[hold.second][i].first});
			}
		}
	}
	
	vector <int> path;
	
	if (dists[n] == 1000000) {
		path.push_back(-1);
	} else {
		int hold = n;
		while (parents[hold] != hold) {
			path.push_back(hold);
			hold = parents[hold];
		}
	}
	
	reverse(path.begin(), path.end());
	
	return path;
}


int main(){
	vector <int> store = {1, 2, 3, 4};

	cout << store.size() << endl;
	store.erase(store.begin() + 1);
	store.erase(store.begin() + 1);
	cout << store.size() << endl;
	indexed_set s;
	s.insert(3);	
	s.insert(4);	
	s.insert(5);	
	s.insert(6);
	cout << *s.find_by_order(2) << endl;	
}
