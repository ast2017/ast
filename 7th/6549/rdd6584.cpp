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
		
		/* ���簢���� �ϳ��� �Է¹޴´ٰ� ���� ��, ������ ���Դ� ���簢�� �� ���� ���簢������ Ű�� ū���� Ž���� �ʿ����� ������ �� �� �ִ�.�� ������ �̿��ؼ� �������� ������ �ذ��� �� �ִ�. */
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