#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int INF = 1111111111;
int MakeTree_Max(vector<int> &Arr, vector<int> &Make, int node, int left, int right){
	if(left == right)
		return Make[node] = Arr[left];
	int mid = (left + right) / 2;
	return Make[node] = max(MakeTree_Max(Arr, Make, node * 2, left, mid), 
		MakeTree_Max(Arr, Make, node * 2 + 1, mid + 1, right));
}

int MakeTree_Min(vector<int> &Arr, vector<int> &Make, int node, int left, int right){
	if(left == right)
		return Make[node] = Arr[left];
	int mid = (left + right) / 2;
	return Make[node] = min(MakeTree_Min(Arr, Make, node * 2, left, mid), 
		MakeTree_Min(Arr, Make, node * 2 + 1, mid + 1, right));
}

int Query_Max(vector<int> &Arr, int node, int left, int right, int start, int end){
	if(right < start || left > end)
		return -INF;
	if(start <= left && right <= end)
		return Arr[node];
	int mid = (left + right) / 2;
	return max(Query_Max(Arr, node * 2, left, mid, start, end), 
		Query_Max(Arr, node * 2 + 1, mid + 1, right, start, end));
}

int Query_Min(vector<int> &Arr, int node, int left, int right, int start, int end){
	if(right < start || left > end)
		return INF;
	if(start <= left && right <= end)
		return Arr[node];
	int mid = (left + right) / 2;
	return min(Query_Min(Arr, node * 2, left, mid, start, end), 
		Query_Min(Arr, node * 2 + 1, mid + 1, right, start, end));
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	vector<int> Arr(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> Max(tree_size);
	vector<int> Min(tree_size);

	for(int i = 1; i <= n; i++)
		scanf("%d", &Arr[i]);

	MakeTree_Max(Arr, Max, 1, 1, n);
	MakeTree_Min(Arr, Min, 1, 1, n);

	while(m--){
		int a, b; scanf("%d %d", &a, &b);
		printf("%d %d\n", Query_Min(Min, 1, 1, n, a, b), Query_Max(Max, 1, 1, n, a, b));
	}

	return 0;
}