#include <cstdio>
#include <queue>
using namespace std;

char vec[2][200001];
char visit[2][200001];

struct node{
	int val;
	int count;
	int dir;
};

queue<node> q;
// q가 비거나, 목표에 도달할 때까지 BFS 반복.
// 숨바꼭질 문제와 같이 이런 뒤로가는 연산이 있는 경우, DP나 DFS로는 풀이가 힘든 것 같다.

int main(){
	int n, k;
	node v, tv;
    scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++)
		scanf("%1d", &vec[0][i]);
		
	for(int i = 0; i < n; i++)
		scanf("%1d", &vec[1][i]);
		
	q.push( {0, 0, 0} );
	visit[1][0] = visit[0][0] = 1;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		if(v.val >= n) { printf("1"); return 0; }
		if(v.count > v.val || !vec[v.dir][v.val]) continue;
	
		if(!visit[v.dir][v.val + 1]) q.push( {v.val + 1, v.count + 1, v.dir} );
		if(!visit[v.dir][v.val - 1]) q.push( {v.val - 1, v.count + 1, v.dir} );
		if(!visit[v.dir ? 0 : 1][v.val + k]) q.push( {v.val + k, v.count + 1, v.dir ? 0 : 1} );
		visit[v.dir][v.val + 1] = visit[v.dir][v.val - 1] = visit[v.dir ? 0 : 1][v.val + k] = 1;
	}
	
	printf("0");
}