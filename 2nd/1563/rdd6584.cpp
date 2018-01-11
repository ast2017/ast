#include<stdio.h>

int n;
int dp[1001][2][3] = {0};

/* ���±��� ������ Ƚ�� l, �������� �Ἦ�� Ƚ�� a�� ���� ���� ������ �����Ѵ�.
*/
int go(int len, int l, int a){
	if(dp[len][l][a])
		return dp[len][l][a];
	if(len >= n)
		return 1;
	
	int count = 0;
	
	if(l == 0) {count += go(len+1, l+1, 0);}
	if(a != 2) {count += go(len+1, l, a+1);}
	count += go(len+1, l, 0);

	return dp[len][l][a] = count % 1000000;
}

int main(){
	scanf("%d", &n);
	printf("%d\n" ,go(0, 0, 0));
}