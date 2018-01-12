#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	while(n--) {
		int score = 0;
		char str[30] = {0,};
		gets_s(str);
		for(int i = 0; str[i]; i++) {
			if(str[i] == ' ') continue;
			score += str[i] - 64;
		}
		if(score == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", score);
	}

	return 0;
}