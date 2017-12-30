#include <cstdio>

int dis[100000];
int cost[100000];

int main() {
	int n, minc = 1111111111;
    long long dp = 0;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
		scanf("%d", &dis[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);

	
	for (int i = 1; i < n; i++) {	// 여태까지 방문했던 지점 중 가장 저렴한 곳에서 사는 것이 최선
		if (minc > cost[i - 1]) minc = cost[i - 1];
		dp += 1LL * minc * dis[i];
	}
	printf("%lld", dp);
}