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

int worm(int i, int x) {
	if (tree[i] < x) return worm(i + 1, x - tree[i]);
	if (i >= szz) return i - szz;
	return worm(i * 2, x);
}

int loca[100000];
int vec[100000];
int ori[100000];

int main() {
	int n, temp;
	
	scanf("%d", &n);
	szz = 1;
	while (szz < n) szz *= 2;

	fill(tree + szz, tree + szz + n, 1);
	init(1);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &ori[i]);
	sort(ori, ori + n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
		
	for (int i = n - 1; i >= 0; i--) {
		temp = worm(1, vec[i] + 1);
		update(temp, 0);
		loca[temp] = i;
	}
	
	for (int i = 0; i < n; i++)
		vec[loca[i]] = ori[i];
		
	for (int i = 0; i < n; i++)
		printf("%d\n", vec[i]);
}