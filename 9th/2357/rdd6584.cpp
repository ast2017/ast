// 최소 최대를 한 노드에 담아서 처리함. 세그.
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int max, min;
};

node tree[262144];
int size = 1;

void init(int i){
	if(i >= size) return;
	init(i * 2), init(i * 2 + 1);
	tree[i].min = min(tree[i * 2].min, tree[i * 2 + 1].min);
	tree[i].max = max(tree[i * 2].max, tree[i * 2 + 1].max);
}

node find(int i, int l, int r, int ll, int rr){
    node t, tt;
	if(l > rr || r < ll) { t.min = 2e+9, t.max = -2e+9; return t; }
	if(ll >= l && rr <= r) return tree[i];
    t = find(i * 2, l, r, ll, (ll + rr) / 2);
    tt = find(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr);
    t.min = min(t.min, tt.min);
    t.max = max(t.max, tt.max);
    
	return t;
}

int main(){
	int n, m, a, b;
    node ans;
	scanf("%d %d", &n, &m);
	while (size < n) size *= 2;
	
	for(int i = size; i < size * 2; i++)
		tree[i].max = -2e9, tree[i].min = 2e9;
		
	for(int i = 0; i < n; i++) {
		scanf("%d", &tree[i + size].min);
		tree[i + size].max = tree[i + size].min;
	}
	init(1);
		
	while(m--){
		scanf("%d %d", &a, &b);
        ans = find(1, a - 1, b - 1, 0, size - 1);
		printf("%d %d\n", ans.min, ans.max);
	}
}