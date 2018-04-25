#include <cstdio>
#include <algorithm>
using namespace std;
int tree[1048576];
int szz;

void init(int i) {
	if (i >= szz) return;
	init(i * 2), init(i * 2 + 1);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int i, int val) {
	i += szz;
	tree[i] += val;
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

int main() {
	int n, m, temp;
	int a, b, c;
	
	scanf("%d", &n);
	szz = 1;
	while (szz < n) szz *= 2;
	
	for(int i = 0; i < n; i++)
		scanf("%d", &tree[i + szz]);
	init(1);
	
	scanf("%d", &m);
	while(m--){
		scanf("%d", &a);
		if(a == 1) {
			scanf("%d %d", &b, &c);
			update(b - 1, c);
		}
		else {
			scanf("%d", &b);
			printf("%d\n", worm(1, b) + 1);
		}
	}
}