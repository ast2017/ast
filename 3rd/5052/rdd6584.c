#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[10000][11];
int cmp(const void *v1, const void *v2){
	return strcmp(v1, v2);
}

/* ���������� ���� �� a�� ���λ� b�� �׻�, a�� �տ� ���� ������ �ִٴ� ���� �̿� */
int main(){
	int t, n, len;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%s", s[i]);
			
		qsort(s, n, sizeof(s[0]), cmp);
		for(int i = 0; i < n - 1; i++){
			len = strlen(s[i]);
			if(len < strlen(s[i+1]))
				for(int j = 0; j < len; j++){
					if(s[i][j] == s[i+1][j]){
						if(j == len - 1){
							printf("NO\n");
							goto end;
						}
						continue;
					}
					else break;
				}
		}
		printf("YES\n");
		end:;
	}
}