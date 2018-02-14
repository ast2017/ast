#include<stdio.h>
#include<math.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)

/* A가 커질수록 만들어지는 상자의 수도 마찬가지로 커진다. 이 성질을 이용해서
이분탐색을 돌릴 수 있다. 실수오차에 대해서는 이분탐색을 단순 100번 돌리는 등으로
오차를 줄일 수 있음. */
int main(){
	long long n, a, b, c, temp;
	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
	double min = MIN(MIN(a,b), c);
	int count = 0;
	
	double l = 1 / n, r = min, mid, max = 0;
	
	while(l < r && count < 100){
		count++;
		mid = (l + r) / 2;
		temp = (long long)(a / mid) * (long long)(b / mid) * (long long)(c / mid);
		
		if(temp < n) r = mid;
		else {l = mid; if(max < mid) max = mid;}
	}
	
	printf("%.10lf", max);
}