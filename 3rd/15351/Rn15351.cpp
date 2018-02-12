#include <stdio.h>
int main() {
    int N;
    scanf("%d ", &N);
    for (; N--; ) {
        char Str[31];
        int i, Point = 0;
        gets(Str);
        for (i = 0; Str[i]; ++i) {
            if (Str[i] >= 'A' && Str[i] <= 'Z') {
                Point += Str[i] - 'A' + 1;
            }
        }
        if (Point == 100) puts("PERFECT LIFE");
        else printf("%d\n", Point);
    }
}
