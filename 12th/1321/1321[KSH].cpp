#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int MakeTree(vector<int> &arr, vector<int> &sum, int node, int left, int right) {
	if(left == right)
		return sum[node] = arr[left];
	int mid = (left + right) / 2;
	return sum[node] = MakeTree(arr, sum, node * 2, left, mid) + 
		MakeTree(arr, sum, node * 2 + 1, mid + 1, right);
}

int Update(vector<int> &sum, int node, int left, int right, int index, int val) {
	if(left > index || right < index)
		return sum[node];
	if(left == right)
		return sum[node] = val;
	int mid = (left + right) / 2;
	return sum[node] = Update(sum, node * 2, left, mid, index, val) 
		+ Update(sum, node * 2 + 1, mid + 1, right, index, val);
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
	vector<int> arr(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> sum(tree_size);

	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	MakeTree(arr, sum, 1, 1, n);

	int t; scanf("%d", &t);
	while(t--) {
		int a, b, c; scanf("%d", &a);
		if(a == 1) {
			scanf("%d %d", &b, &c);
			arr[b] += c;
 			Update(sum, 1, 1, n, b, arr[b]);
		} else {
			scanf("%d", &b);
			printf("%d\n", Query(sum, 1, 1, n, b));
		}
	}
	return 0;
}