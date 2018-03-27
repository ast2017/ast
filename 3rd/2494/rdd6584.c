#include<stdio.h>

int dp[10001][10][2] = {0};
int vec[10001];
int ob[10001];

int top = -1;
int n, pp = 0, tt;

/* go 함수는 지난번 문제와 동일함. 다만 DP[x][p][1]에 추가적으로 이 단계에서 왼쪽으로 도는것이 최선인지 오른쪽이 도는 것이 최선인지 기록해준다. */
// 방법출력X 숫자맞추기 선행. 왼쪽 오른쪽중 최적인 연산을 저장해주고, 그에 따른 복원.

int go(int x, int p){
    if(x >= n+1) return 0;
	if(dp[x][p][0] != -1) return dp[x][p][0];

	int c1, c2, temp = (vec[x] + p) % 10;

	if(temp < ob[x]){
		c1 = ob[x] - temp + go(x+1, (p + ob[x] - temp) % 10);
		c2 = 10 + temp - ob[x] + go(x+1, p);
	}
	else if(temp > ob[x]){
		c1 = 10 + ob[x] - temp + go(x+1, (p + 10 + ob[x] - temp) % 10);
		c2 = temp - ob[x] + go(x+1, p);
	}
	else {dp[x][p][1] = 2; return dp[x][p][0] = go(x+1, p);}
	
	if(c1 < c2)	{dp[x][p][1] = 1; return dp[x][p][0] =  c1;}
	else {dp[x][p][1] = 3; return dp[x][p][0] = c2;}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%1d", &vec[i]);
	for(int i = 1; i <= n; i++) scanf("%1d", &ob[i]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 9; j++)
			dp[i][j][0] = -1;

	printf("%d\n", go(1, 0));
	
/* 기록된 DP[x][p][1]을 이용해서 해당 단계의 오른쪽 왼쪽으로의 연산을 복원해준다*/
	for(int i = 1; i <= n; i++){
		tt = (vec[i] + pp) % 10;
		if(dp[i][pp][1] == 1){
			if(tt < ob[i]){
				printf("%d %d\n", i, ob[i] - tt);
				pp = (pp + ob[i] - tt) % 10;
			}
			else {
				printf("%d %d\n", i, 10 + ob[i] - tt);
				pp = (pp + 10 + ob[i] - tt) % 10;
			}
		}
		else if(dp[i][pp][1] == 3){
			if(tt < ob[i])
				printf("%d %d\n", i, (10 + tt - ob[i]) * -1);
			else
				printf("%d %d\n", i, (tt - ob[i]) * -1);
		} 
	}
}