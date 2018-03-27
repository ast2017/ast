#include <cstdio>
#include <memory.h>

int vec[100000], temp[100000];
/* 만들려고 하는 최대차이가 감소함에 따라서 써야하는 횟수는 많아짐이 자명하다.
따라서 최대차이에 따라서 이분탐색을 적용해 해결할 수 있다.
탐색은 왼쪽부터 한번 훑고, 다시 오른쪽부터 한번 훑는 것으로 해결할 수 있다. */

int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	int l, r, mid, sum;
	
	for(int i = 0; i < n; i++)
		scanf("%d", &vec[i]);	

	l = 0, r = (1e+9) - 1;
	while(l <= r){
		sum = 0;
		mid = (l + r) / 2;
		memcpy(temp, vec, sizeof(temp));
		
		for(int i = 0; i < n - 1; i++)
			if(temp[i] + mid < temp[i + 1]){
				sum += temp[i + 1] - temp[i] - mid;
				temp[i + 1] = temp[i] + mid;
			}
		for(int i = n - 1; i > 0; i--)
			if(temp[i] + mid < temp[i - 1]){
				sum += temp[i - 1] - temp[i] - mid;
				temp[i - 1] = temp[i] + mid;
			}
			
		if(sum > t) l = mid + 1;
		else r = mid - 1;
	}
	
	mid = l;
	memcpy(temp, vec, sizeof(temp));
	for(int i = 0; i < n - 1; i++)
		if(temp[i] + mid < temp[i + 1])
			temp[i + 1] = temp[i] + mid;
			
	for(int i = n - 1; i > 0; i--)
		if(temp[i] + mid < temp[i - 1])
			temp[i - 1] = temp[i] + mid;
	
	for(int i = 0; i < n; i++)
		printf("%d ", temp[i]);
}