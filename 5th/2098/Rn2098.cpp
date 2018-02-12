#include <stdio.h>
#include <memory.h>
#define INF 987654321
int Map[16][16];
int DP[16][65536][16];
int N;
int MIN(int I, int J) {
    return I < J ? I : J;
}
int Find(int I, int J, int K) {
    if (DP[I][J][K] != -1) return DP[I][J][K];
    DP[I][J][K] = INF;
    int i, Bit, Flag = 1;
    for (i = 0, Bit = J & ((1 << N) - 1); i < N; ++i, Bit >>= 1) {
        if (!(Bit & 1)) {
            Flag = 0;
            DP[I][J][K] = MIN(DP[I][J][K], Find(I, J + (1 << i), i) + Map[K][i]);
        }
    }
    if (Flag) DP[I][J][K] = Map[K][I];
    return DP[I][J][K];
}
int main() {
    int i, j, Min = INF;
    memset(DP, -1, sizeof(DP));
    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", Map[i] + j);
            Map[i][j] = Map[i][j] + !Map[i][j] * INF;
        }
    }
    for (i = 0; i < N; ++i) {
        Min = MIN(Min, Find(i, 1 << i, i));
    }
    printf("%d", Min);
	return 0;
}
