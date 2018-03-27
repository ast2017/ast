#include <cstdio>
#include <algorithm>
using namespace std;

int dp[2][30001];
// 지난번 같은탑 축소버전. 동일한 풀이
int main(){
	int n, m, temp;
	int *p = dp[0], *q = dp[1];
	scanf("%d", &n);
	
	p[15000] = 1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		for(int j = 30000; j >= 0; j--){
			q[j] |= p[j];
			if(j + temp <= 30000) q[j] |= p[j + temp];
			if(j - temp >= 0) q[j] |= p[j - temp];
		}
		swap(p, q);
	}		
	
	scanf("%d", &m);
	while(m--){
		scanf("%d", &temp);
		if(temp > 15000) {printf("N "); continue;}
		if(p[15000 - temp]) printf("Y ");
		else printf("N ");
	}
}