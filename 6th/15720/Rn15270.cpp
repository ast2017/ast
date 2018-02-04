#include <stdio.h>
int N, Map[21][21], Vis[21];
int MAX(int I, int J) {
    return I > J ? I : J;
}
int MIN(int I, int J) {
    return I < J ? I : J;
}
int Find(int I, int J) {
    if (I == N + 1) return J;
    int i, Res = 0;
    for (i = 1; i <= N; ++i) {
        if (Map[I][i] & !Vis[i] & !Vis[I]) {
            Vis[I] = Vis[i] = 1;
            Res = MAX(Res, Find(I + 1, J + 2));
            Vis[I] = Vis[i] = 0;
        }
    }
    return MAX(Res, Find(I + 1, J));
}
int main() {
    int i, K;
    scanf("%d%d", &N, &K);
    for (i = 0; i < K; ++i) {
        int X, Y;
        scanf("%d%d", &X, &Y);
        Map[X][Y] = Map[Y][X] = 1;
    }
    printf("%d", MIN(Find(1, 0) + 1, N));
    return 0;
}
