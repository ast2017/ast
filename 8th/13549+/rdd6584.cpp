#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int visit[200001];

// BFS�� Ǯ�� ���ؼ�, �տ� ������ cost�� �׻� �ں��� �۾ƾ� �Ѵ�. ���� �� ������ �����ֱ� ���ؼ�
// ���� �������� ������ *2�� �� �۶߷��ָ�, �׻� �� ������ ��Ű�鼭 Ž���� �� �ִ�.

int main(){
	int n, k;
	pii v, tv;
	scanf("%d %d", &n, &k);
	
	q.push( {n, 0} );
	visit[n] = 0;
	
	while(1) {
		v = q.front();
		q.pop();
		
		if(v.first == k) { printf("%d", v.second); return 0; }
		tv = v;
		
		while(tv.first * 2 <= 200000 && tv.first != 0 && !visit[tv.first * 2]){
			tv.first *= 2;
			visit[tv.first] = 1;
			q.push(tv);
		}
		
		if(v.first > 0 && !visit[v.first - 1]) {q.push( {v.first - 1, v.second + 1} ); visit[v.first - 1] = 1;}
		if(v.first < k && !visit[v.first + 1]) {q.push( {v.first + 1, v.second + 1} ); visit[v.first + 1] = 1;}
	}
}