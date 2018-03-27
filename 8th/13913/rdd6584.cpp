#include <cstdio>
#include <queue>
#include <memory.h>
#include <vector>
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int dp[200001];
vector<int> vec;

// ��� �������� ���ؼ�, ���� ���� �� �� �ִ� �� Where is from
// ��, �ش� �ε����� ��� �Դ��� �����ϴ� �迭 ����. (�迭�̸��� dp�� ���� X)

int main(){
	int n, k;
	pii v, tv;
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	
	q.push( {n, 0} );
	dp[n] = 999999;
	
	while(1) {
		v = q.front();
		q.pop();
		
		if(v.fi == k) {
			printf("%d\n", v.se);
			
			while(v.fi != n) {
				vec.push_back(v.fi);
				v.fi = dp[v.fi];
			}
			vec.push_back(n);
			for(int i = v.se; i >= 0; i--) printf("%d ", vec[i]);
			return 0;
		}
		
		if(v.fi * 2 <= 200000 && v.fi != 0) {
			if(dp[v.fi * 2] == -1) {
				q.push( {v.fi * 2, v.se + 1} );
				dp[v.fi * 2] = v.fi;
			}
		}
		
		if(v.fi > 0){
			if(dp[v.fi - 1] == -1) {
				q.push( {v.fi - 1, v.se + 1} );
				dp[v.fi - 1] = v.fi;
			}
		}
		
		if(v.fi < k){
			if(dp[v.fi + 1] == -1) {
				q.push( {v.fi + 1, v.se + 1} );
				dp[v.fi + 1] = v.fi;
			}
		}
	}
}