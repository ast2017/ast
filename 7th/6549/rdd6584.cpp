#include <cstdio>

typedef long long ll;

struct node{
	ll h, l;
};

node stk[100001];
int top;

int main(){
	int n, j;
	ll temp, max, tt;
	stk[0].h = -2;
	
	while(1){
		scanf("%d", &n);
		if(!n) break;
		
		top = 0, max = 0;
		
		/* 직사각형을 하나씩 입력받는다고 했을 때, 이전에 나왔던 직사각형 중 현재 직사각형보다 키가 큰것은 탐색에 필요하지 않음을 알 수 있다.이 성질을 이용해서 스택으로 문제를 해결할 수 있다. */
		for(int i = 1; i <= n + 1; i++){
			if(i <= n) scanf("%lld", &temp);
			else temp = -1;
			
			for(j = top; temp <= stk[j].h; j--){
				tt = stk[j].h * (stk[top].l - stk[j - 1].l);
				max = (max < tt ? tt : max);
			}
			
			top = j;
			stk[++top].h = temp, stk[top].l = i;
		}
		
		printf("%lld\n", max);
	}
}