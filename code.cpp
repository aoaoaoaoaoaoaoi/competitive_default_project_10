#include <bits/stdc++.h>
using namespace std;

#define INF /*1000000007*/ 5000000000000000003
#define MOD 1000000007
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); ++i)

const double PI = acos(-1);

//printf("%.10f", );
//vector<vector<int>> data(3, vector<int>(4, -1));

/***********************************************************************/

int main() {
  int n, m; cin >> n >> m;
  vector<ll>a(n);
  rep(i, n){
    cin >> a[i];
  }
  vector<ll>b(m);
  rep(i, m){
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  ll ans = INF;
  rep(ai, a.size()){
    int ok = -1;
    int ng = b.size();
    while(ng - ok > 1){
      int mid = (ok + ng) / 2;
      if(b[mid] <= a[ai]){
        ok = mid;
      }else{
        ng = mid;
      }
    }
    
    if(0 <=ok && ok < b.size()){
      ans = min(ans, abs(a[ai]-b[ok]));
    }
    if(ok < ((int)(b.size()) - 1)){
      ans = min(ans, abs(a[ai]-b[ok+1]));
    }
  }

  cout << ans << endl;
}