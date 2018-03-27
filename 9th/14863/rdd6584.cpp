// version1
// DP[순서][시간합] = 모금액합으로 구성하여 해결.
#include <cstdio>

int vec[100][4];
int dp[100][100001];
int n, k;

int go(int o, int li){
	if(li > k) return -123456789;
	if(o == n) return 0;
	if(dp[o][li]) return dp[o][li];
	
	int c1 = go(o + 1, li + vec[o][0]) + vec[o][1], c2 = go(o + 1, li + vec[o][2]) + vec[o][3];
	return dp[o][li] = c1 > c2? c1 : c2;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d %d", &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]);
	
	printf("%d", go(0, 0));
}

// version2
// 반복문풀이로 메모리 줄인 버젼. 서브셋섬 풀이와 유사.
#include <cstdio>
#include <queue>
#define MAX(a, b) (a) > (b) ? (a) : (b)
using namespace std;

int vec[100][4];
int dp[100001];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d %d", &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]);
	
	for(int i = 0; i < n; i++)
		for(int j = k; j >= 0; j--){
			dp[j] = -123456789;
			if(j >= vec[i][0]) dp[j] = MAX(dp[j], dp[j - vec[i][0]] + vec[i][1]);
			if(j >= vec[i][2]) dp[j] = MAX(dp[j], dp[j - vec[i][2]] + vec[i][3]);
		}
	
	printf("%d", dp[k]);
}