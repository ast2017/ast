#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int MakeTree(vector<int> &sum, int node, int left, int right) {
	if(left == right)
		return sum[node] = 1;
	int mid = (left + right) / 2;
	return sum[node] = MakeTree(sum, node * 2, left, mid) +
		MakeTree(sum, node * 2 + 1, mid + 1, right);
}


void Update(vector<int> &sum, int node, int left, int right, int val) {
	if(left == right) {
		sum[node] = 0;
		return;
	}
	int mid = (left + right) / 2;

	if(val <= mid)
		Update(sum, node * 2, left, mid, val);
	else
		Update(sum, node * 2 + 1, mid + 1, right, val);

	sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

int Query(vector<int> &sum, int node, int left, int right, int v) {
	if(left == right)
		return left;
	int mid = (left + right) / 2;
	if(v <= sum[node * 2])
		return Query(sum, node * 2, left, mid, v);
	return Query(sum, node * 2 + 1, mid + 1, right, v - sum[node * 2]);
}

int main() {
	int n; scanf("%d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> arr(n + 1);
	vector<int> num(n + 1);
	vector<int> ans(n + 1);
	vector<int> sum(tree_size);

	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	MakeTree(sum, 1, 1, n);
	sort(arr.begin(), arr.end());

	for(int i = 1; i <= n; i++) scanf("%d", &num[i]);

	for(int i = n; i >= 1; i--) {
		int ret = Query(sum, 1, 1, n, num[i] + 1);
		Update(sum, 1, 1, n, ret);
		ans[i] = arr[ret];
	}

	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);

	return 0;
}
