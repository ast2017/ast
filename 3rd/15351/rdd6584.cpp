#include <cstdio>
#include <cstring>

int main() {
	int n;
	int sum, len;
	char s[31], c;
	scanf("%d", &n);

	while (n--) {
		scanf("%c", &c);
		scanf("%[^\n]s", s);
		sum = 0;
		len = strlen(s);
		
		for (int i = 0; i < len; i++) 
			if(s[i] != ' ') sum += s[i] - 'A' + 1;

		if (sum == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", sum);
	}
}