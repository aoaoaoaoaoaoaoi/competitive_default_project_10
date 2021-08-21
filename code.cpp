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
	
  map<ll, ll>Lm;
void calcPrimeDecomposition(int target) {
		ll mx = sqrt(target);
		for (ll j = 2; j <= mx;) {
 
			while (target % j == 0) {
				++Lm[j];
				target /= j;
			}
 
			if (j == 2) {
				++j;
			}
			else {
				j += 2;
			}
		}
		if (target != 1) {
			++Lm[target];
		}
}

bool isCalcPrimeDecomposition(int target) {
		ll mx = sqrt(target);
		for (ll j = 2; j <= mx;) {
 
			while (target % j == 0) {
				if(0 < Lm[j]){
          return false;
        }
				target /= j;
			}
 
			if (j == 2) {
				++j;
			}
			else {
				j += 2;
			}
		}
		if (target != 1) {
      if(0 < Lm[target]){
        return false;
      }
		}
    return true;
}

int main() {
  int n , m; cin >> n >> m;

    cout << ans << endl;
}