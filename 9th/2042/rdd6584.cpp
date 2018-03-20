#include<stdio.h>

long long tree[1000001] = {0};
int n, m, k;

void update(int i, long long num){
	while(i <= n){
		tree[i] += num;
		i += (i & -i);
	}
}

long long find(int i){
	long long sum = 0;
	while(i > 0){
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

int main(){
	int a, b, c;
    long long temp;
	scanf("%d %d %d", &n, &m, &k);
	
	m += k;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &temp);
		update(i, temp);
	}
	
	while(m--){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) {
			temp = find(b) - find(b-1);
			update(b, c - temp);
		}
		else if(a == 2) printf("%lld\n", find(c) - find(b-1));
	}
}