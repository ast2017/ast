#include<stdio.h>
#define swap(a,b,t) (t) = (a), (a) = (b), (b) = (t)

int vec[50];
int temp[50];

int main(){
	int n, s, t;
	int tt, kk;
	
	while(scanf("%d", &n) != -1){
		tt = 0; kk = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &vec[i]);
			temp[i] = vec[i];
		}
		scanf("%d", &s);
		
		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < n - 1; j++)
				if(temp[j] < temp[j + 1]) swap(temp[j], temp[j + 1], t);
				
		while(s && tt < n){	// 남은 s로 갈 수 있으면 스왑.
			for(int i = 0; i < n && tt != -1 && temp[tt]; i++)
				if(temp[tt] == vec[i]){
					if(i-kk <= s) {
						for(int j = i; j > kk; j--){
							if(vec[j] < vec[j - 1]) break;
							swap(vec[j], vec[j-1], t);
							s--;
						}
						kk++;
						temp[tt] = 0;
						tt = -1; 
					}
					else break;
				}
			tt++;
			
		}
		
		for(int i = 0; i < n; i++)
			printf("%d ", vec[i]);
        printf("\n");
	}
}