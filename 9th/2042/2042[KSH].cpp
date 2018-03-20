#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

ll MakeTree(vector<int> &arr, vector<ll> &sum, int node, int left, int right){
	if(left == right)
		return sum[node] = arr[left];
	int mid = (left + right) / 2;
	return sum[node] = MakeTree(arr, sum, node * 2, left, mid) + MakeTree(arr, sum, node * 2 + 1, mid + 1, right);
}

ll Update(vector<int> &arr, vector<ll> &sum, int node, int left, int right, int index, int val){
	if(left > index || right < index)
		return sum[node];
	if(left == right)
		return sum[node] = arr[index] = val;
	int mid = (left + right) / 2;
	return sum[node] = Update(arr, sum, node * 2, left, mid, index, val) + Update(arr, sum, node * 2 + 1, mid + 1, right, index, val);
}

ll Query(vector<ll> &sum, int node, int left, int right, int start, int end){
	if(start > right || end < left)
		return 0;
	if(start <= left && right <= end)
		return sum[node];
	int mid = (left + right) / 2;
	return Query(sum, node * 2, left, mid, start, end) + Query(sum, node * 2 + 1, mid + 1, right, start, end);
}

int main(){
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	vector<int> arr(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> sum(tree_size);

	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	MakeTree(arr, sum, 1, 1, n);
	int t = m + k;
	while(t--){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if(a == 1)
			Update(arr, sum, 1, 1, n, b, c);
		else
			printf("%lld\n", Query(sum, 1, 1, n, b, c));
	}
	return 0;
}