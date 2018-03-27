// 그리디. 끝나는 시간 순으로 정렬하고 순서대로 들어가는 것이 최적.
#include <cstdio>
#include <algorithm>

struct node {
	int s, e;
};

node vec[100000];

bool cmp(node v1, node v2) {
	if (v1.e != v2.e) return v1.e < v2.e;
	return v1.s < v2.s;
}

int main() {
	int n, temp = 0, count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &vec[i].s, &vec[i].e);

	sort(vec, vec + n, cmp);
	for (int i = 0; i < n; i++)
		if (temp <= vec[i].s) {
			temp = vec[i].e; 
			count++;
		}

	printf("%d", count);
}