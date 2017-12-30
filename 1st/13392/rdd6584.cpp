#include<stdio.h>

int dp[10001][10];
int vec[10001];
int ob[10001];

int n;
/* ���� �ܰ迡�� ������ ���� ���� �ܰ迡�� ������ ���� �ʴ´�.
���������� �������� ���纸��. ���� �ܰ踦 �ϳ��� ���� ������ ������ �� �ִ�.
���±��� ���������� ���� Ƚ���� p��� ���� ��, ���Ŀ� ������ ��� ���翡 ���ؼ���
��� �����ϰ� p�� ��ŭ ���ư� ������ ���̴�. �׸��� p�� 11�̵� 1�̵� �Ȱ���.
�� ������� ���ؼ� ���� x�ܰ�, p�� ���� ����Լ��� �׻� ���� ��������
��ȯ�Ѵٴ� ���� �� �� �ִ�. */
int go(int x, int p){
    if(x >= n+1) return 0;
	if(dp[x][p] != -1) return dp[x][p];

	int c1, c2, temp = (vec[x] + p) % 10; // temp�� ���� ���ڿ��� p��ŭ ���ư� ���ڷ� ����

	if(temp < ob[x]){
		c1 = ob[x] - temp + go(x+1, (p + ob[x] - temp) % 10);
		c2 = 10 + temp - ob[x] + go(x+1, p);
	}
	else if(temp > ob[x]){
		c1 = 10 + ob[x] - temp + go(x+1, (p + 10 + ob[x] - temp) % 10);
		c2 = temp - ob[x] + go(x+1, p);
	}
	else return dp[x][p] = go(x+1, p);
	
	if(c1 < c2)	return dp[x][p] =  c1;	// �������� ���� �Ͱ� ���������� ������ �� �� �� ���� ���� ��ȯ.
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