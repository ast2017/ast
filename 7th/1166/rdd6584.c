#include<stdio.h>
#include<math.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)

/* A�� Ŀ������ ��������� ������ ���� ���������� Ŀ����. �� ������ �̿��ؼ�
�̺�Ž���� ���� �� �ִ�. �Ǽ������� ���ؼ��� �̺�Ž���� �ܼ� 100�� ������ ������
������ ���� �� ����. */
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