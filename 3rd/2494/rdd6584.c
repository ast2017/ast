#include<stdio.h>

int dp[10001][10][2] = {0};
int vec[10001];
int ob[10001];

int top = -1;
int n, pp = 0, tt;

/* go �Լ��� ������ ������ ������. �ٸ� DP[x][p][1]�� �߰������� �� �ܰ迡�� �������� ���°��� �ּ����� �������� ���� ���� �ּ����� ������ش�. */
// ������X ���ڸ��߱� ����. ���� �������� ������ ������ �������ְ�, �׿� ���� ����.

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
	
/* ��ϵ� DP[x][p][1]�� �̿��ؼ� �ش� �ܰ��� ������ ���������� ������ �������ش�*/
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