#include <cstdio>
#include <memory.h>

int vec[100000], temp[100000];
/* ������� �ϴ� �ִ����̰� �����Կ� ���� ����ϴ� Ƚ���� �������� �ڸ��ϴ�.
���� �ִ����̿� ���� �̺�Ž���� ������ �ذ��� �� �ִ�.
Ž���� ���ʺ��� �ѹ� �Ȱ�, �ٽ� �����ʺ��� �ѹ� �ȴ� ������ �ذ��� �� �ִ�. */

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