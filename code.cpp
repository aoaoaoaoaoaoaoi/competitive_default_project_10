#include <bits/stdc++.h>
using namespace std;

#define INF 1001001001
#define LINF 1001001001001001001
#define MOD 1000000007
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); ++i)

const double PI = acos(-1);

//printf("%.10f", );
//vector<vector<int>> data(n);
//vector<vector<int>> data(3, vector<int>(4, -1));
//priority_queue<ll, vector<ll>, greater<ll>>que; 小さい順の優先度つきキュー

/***********************************************************************/

struct UnionFind {
	vector<int>uf;
 
	UnionFind(int size) :uf(size, -1) {};
 
	int root(int target) {
		if (uf[target] < 0)return target;
		else return uf[target] = root(uf[target]);
	}
 
  int size(int target) {
    if(0 <= uf[target]){
      return -uf[root(target)];
    }
    return -uf[target];
  }

	void merge(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b)return;
		if (uf[b] < uf[a])swap(a, b);
		uf[a] += uf[b];
		uf[b] = a;
	}
};

int main() {
  int n; cin >> n;
  vector<tuple<ll, ll, ll>> edge(n-1);

  rep(i, n-1){
    int u, v; cin >> u >> v; --u; --v; 
    ll w; cin >> w;
    edge[i] = make_tuple(w, u, v);
  }

  sort(edge.begin(), edge.end());
  ll ans = 0;
  UnionFind u = UnionFind(n);
  for(auto e : edge){
    ans += get<0>(e) * u.size(get<1>(e)) * u.size(get<2>(e));
    u.merge(get<1>(e), get<2>(e));
  }

  cout << ans << endl;
}