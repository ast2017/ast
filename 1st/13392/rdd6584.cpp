#include<stdio.h>

int dp[10001][10];
int vec[10001];
int ob[10001];

int n;
/* 이전 단계에서 맞춰진 수는 이후 단계에서 영향을 받지 않는다.
위에서부터 차곡차곡 맞춰보자. 남은 단계를 하나의 작은 문제로 생각할 수 있다.
여태까지 오른쪽으로 돌린 횟수를 p라고 했을 때, 이후에 나오는 모든 나사에 대해서도
모두 동일하게 p번 만큼 돌아간 형태일 것이다. 그리고 p는 11이든 1이든 똑같다.
위 성질들로 인해서 인자 x단계, p에 따라서 재귀함수는 항상 같은 최적값을
반환한다는 것을 알 수 있다. */
int go(int x, int p){
    if(x >= n+1) return 0;
	if(dp[x][p] != -1) return dp[x][p];

	int c1, c2, temp = (vec[x] + p) % 10; // temp를 원래 숫자에서 p만큼 돌아간 숫자로 정의

	if(temp < ob[x]){
		c1 = ob[x] - temp + go(x+1, (p + ob[x] - temp) % 10);
		c2 = 10 + temp - ob[x] + go(x+1, p);
	}
	else if(temp > ob[x]){
		c1 = 10 + ob[x] - temp + go(x+1, (p + 10 + ob[x] - temp) % 10);
		c2 = temp - ob[x] + go(x+1, p);
	}
	else return dp[x][p] = go(x+1, p);
	
	if(c1 < c2)	return dp[x][p] =  c1;	// 왼쪽으로 돌린 것과 오른쪽으로 돌리는 것 중 더 작은 값을 반환.
	else return dp[x][p] = c2;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%1d", &vec[i]);
	for(int i = 1; i <= n; i++) scanf("%1d", &ob[i]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 9; j++)
			dp[i][j] = -1;

	printf("%d", go(1, 0));
}