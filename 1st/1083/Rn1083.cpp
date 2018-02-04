#include <stdio.h>
int Ar[50];
void SWAP(int* X, int* Y) {
    *X = *X + *Y;
    *Y = *X - *Y;
    *X = *X - *Y;
}
int main() {
    int i, N, S, M, j, t;
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%d", Ar + i);
        }
        scanf("%d", &S);
        for (t = 0; t < N && S > 0; ++t) {
            for (M = 0, i = j = t; i < t + S + 1 && i < N; ++i) {
                if (M < Ar[i]) {
                    M = Ar[i];
                    j = i;
                }
            }
            for (i = j; i > t; --i, --S) {
                SWAP(Ar + i, Ar + i - 1);
            }
        }
        for (i = 0; i < N; ++i) {
            printf("%d ", Ar[i]);
        }
        puts("");
    }

    return 0;
}
