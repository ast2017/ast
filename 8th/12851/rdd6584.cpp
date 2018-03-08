#include <cstdio>
#include <queue>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
pii dp[200001];

// dp[i].fi는 해당 인덱스를 최단경로로 갈 수 있는 경우의 수.
// dp[i].se는 해당 인덱스가 cost가 몇이여야 최단경로인지.
int main(){
	int n, k;
	pii v, tv;
	scanf("%d %d", &n, &k);
	
	q.push( {n, 0} );
	dp[n].fi = 1, dp[n].se = 0;
	
	while(1) {
		v = q.front();
		q.pop();
		
		if(v.fi == k) { printf("%d\n%d", v.se, dp[v.fi].fi); return 0; }
		
		if(v.fi * 2 <= 200000 && v.fi != 0) {
			if(!dp[v.fi * 2].fi){
				q.push( {v.fi * 2, v.se + 1} );
				dp[v.fi * 2].fi = dp[v.fi].fi;
				dp[v.fi * 2].se = v.se + 1;
			}
			else if(v.se + 1 == dp[v.fi * 2].se) dp[v.fi * 2].fi += dp[v.fi].fi;
		}
		
		if(v.fi > 0){
			if(!dp[v.fi - 1].fi) {
				q.push( {v.fi - 1, v.se + 1} );
				dp[v.fi - 1].fi = dp[v.fi].fi;
				dp[v.fi - 1].se = v.se + 1;
			}
			else if(v.se + 1 == dp[v.fi - 1].se)dp[v.fi - 1].fi += dp[v.fi].fi;
		}
		if(v.fi < k){
			if(!dp[v.fi + 1].fi) {
				q.push( {v.fi + 1, v.se + 1} );
				dp[v.fi + 1].fi = dp[v.fi].fi;
				dp[v.fi + 1].se = v.se + 1;
			}
			else if(v.se + 1 == dp[v.fi + 1].se ) dp[v.fi + 1].fi += dp[v.fi].fi;
		}
	}
}