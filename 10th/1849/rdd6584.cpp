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


int loca[100000]; // ���� ����迭

/*
�����ռ��׸� �̿��� Ǯ��. ���� ������ �Է����� �־����� ���� �̿�.
a[1] = 5���, 1�� 6��°�� ��ġ�� ����. a[2] = 5��� 2�� 7��°�� ��ġ�� ����.
��, sum(0~x) = (a[i] + 1)�� X�� ã�� ������ ������ �� ����. �� loca[x] = i.
�� ������ ���ִ� worm�Լ�. (�̺�Ž���� ���������� �ð����⵵�� �ռ�.)
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