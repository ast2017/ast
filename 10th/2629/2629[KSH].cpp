#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX 15000

int a[35];
int dp[MAX + 5], temp[MAX + 5];
int main(){
	int t, n; scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
	}

	dp[0] = temp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= MAX; j++){
			if(dp[j]){
				int add = abs(a[i] + j);
				int sub = abs(a[i] - j);
				
				temp[a[i]] = 1;
				if(add <= MAX) temp[add] = 1;
				if(sub <= MAX) temp[sub] = 1;
			}
		}
		memcpy(dp, temp, sizeof(temp));
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n > MAX || !dp[n])
			printf("N ");
		else
			printf("Y ");
	}

	return 0;
}