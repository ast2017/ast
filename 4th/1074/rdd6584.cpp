/* 분할정복을 이용한 풀이.
매 구간을 4개의 구간으로 나누어서 갯수를 계산해준다.
*/ 
#include <cstdio>

int n, r, c;
int chk = 1;
int go(int x1, int y1, int x2, int y2, int d) {
	if (!(r >= x1 && c >= y1 && r <= x2 && c <= y2)) return d * d;
	if (d == 1) { chk = 0; return 0; }
	int sum = 0; d /= 2;
	
	if(chk) sum += go(x1, y1, x2 - d, y2 - d, d);
	if(chk) sum += go(x1, y1 + d, x2 - d, y2, d);
	if(chk) sum += go(x1 + d, y1, x2, y2 - d, d);
	if(chk) sum += go(x1 + d, y1 + d, x2, y2, d);

	return sum;
}

int main() {
	scanf("%d %d  %d", &n, &r, &c);
	int t = 1 << n;
	printf("%d", go(0, 0, t - 1, t - 1, t));
}