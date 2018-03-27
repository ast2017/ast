#include <cstdio>
#include <algorithm>
using namespace std;
int tree[262144];
int szz;

void init(int i) {
	if (i >= szz) return;
	init(i * 2), init(i * 2 + 1);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int i, int val) {
	i += szz;
	tree[i] = val;
	i /= 2;

	while (i) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
		i /= 2;
	}
}

int worm(int i, int x, int now) {
	if (tree[i] + now < x) return worm(i + 1, x, now + tree[i]);
	if (i >= szz) return i - szz;
	return worm(i * 2, x, now);
}


int loca[100000]; // 정답 저장배열

/*
구간합세그를 이용한 풀이. 작은 수부터 입력으로 주어지는 점을 이용.
a[1] = 5라면, 1은 6번째에 위치할 것임. a[2] = 5라면 2는 7번째에 위치할 것임.
즉, sum(0~x) = (a[i] + 1)인 X를 찾는 문제로 생각할 수 있음. 즉 loca[x] = i.
위 역할을 해주는 worm함수. (이분탐색도 가능하지만 시간복잡도가 앞섬.)
*/
int main() {
	int n, temp;
	
	scanf("%d", &n);
	szz = 1;
	while (szz < n) szz *= 2;

	fill(tree + szz, tree + szz + n, 1);
	init(1);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		temp = worm(1, temp + 1, 0);
		loca[temp] = i + 1;
		update(temp, 0);
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", loca[i]);
}