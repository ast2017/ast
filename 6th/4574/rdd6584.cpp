// 그냥 음.. 빈 공간을 모두 저장하고 앞에서부터 순서대로 백트래킹
#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

struct node{ char x, y; };

vector<node> v;
char mat[9][9];
char domi[10][10];
char ans, size;
char dx[3] = {0, 1, 0}, dy[3] = {0, 0, 1};

void go(char o){
	if(o == size) ans = 1;
	if(ans) return;
	
	char x =  v[o].x, y = v[o].y;
	if(mat[x][y]) {go(o + 1); return ;}
	char xx, yy;
	
	char vec[3][10] = { 0 };
	
	for(int s = 0; s < 3; s++){
		xx = x + dx[s], yy = y + dy[s];
		if(xx > 8 || yy > 8 || mat[xx][yy]) continue;
		
		for (int i = 0; i < 9; i++)
			vec[s][mat[i][yy]] = 1;

		for (int i = 0; i < 9; i++)
			vec[s][mat[xx][i]] = 1;

		for (int i = xx / 3 * 3; i < xx / 3 * 3 + 3; i++)
			for (int j = yy / 3 * 3; j < yy / 3 * 3 + 3; j++)
				vec[s][mat[i][j]] = 1;
	}
	
	for(int i = 1; i < 10; i++){
		if(!vec[0][i]){
			mat[x][y] = i;
			if(x + 1 < 9 && !mat[x + 1][y]){
				for(int j = 1; j < 10; j++)
					if(!vec[1][j] && !domi[i][j]){
						mat[x + 1][y] = j;
						domi[i][j] = domi[j][i] = 1;
						go(o + 1);
						if(ans) return;
						mat[x + 1][y] = 0;
						domi[i][j] = domi[j][i] = 0;
					}
			}
			
			if(y + 1 < 9 && !mat[x][y + 1]){
				for(int j = 1; j < 10; j++)
					if(!vec[2][j] && !domi[i][j]){
						mat[x][y + 1] = j;
						domi[i][j] = domi[j][i] = 1;
						go(o + 1);
						if(ans) return;
						mat[x][y + 1] = 0;
						domi[i][j] = domi[j][i] = 0;
					}
			}
			mat[x][y] = 0;
		}
	}
}

int main(){
	char t = 0;
	node tv;
	
	while(++t){
		int n, a, c;
		char b[3], d[3];
		scanf("%d", &n);
		
		if(!n) break;
		
		memset(mat, 0, sizeof(mat));
		memset(domi, 0, sizeof(domi));
		v.clear();
		ans = 0;
		
		for(int i = 0; i < n; i++){
			scanf("%d %s %d %s", &a, b, &c, d);
			mat[b[0] - 'A'][b[1] - '1'] = a;
			mat[d[0] - 'A'][d[1] - '1'] = c;
			domi[a][c] = domi[c][a] = 1;
		}
		
		for(int i = 1; i < 10; i++){
			domi[i][i] = 1;
			scanf("%s", b);
			mat[b[0] - 'A'][b[1] - '1'] = i;
		}
		
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				if(!mat[i][j]){
					tv.x = i, tv.y = j;
					v.push_back(tv);
				}
		
		size = v.size();
		go(0);
		
		
		printf("Puzzle %d\n", t);
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++)
				printf("%d", mat[i][j]);
			printf("\n");
		}
	}
}