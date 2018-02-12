#include <algorithm>
#include <cstring>
#include <cstdio>
int Map[301][301], cMap[301][301], N, M;
int Dir_X[4] = { 1, 0, -1, 0 };
int Dir_Y[4] = { 0, 1, 0, -1 };
inline bool InMap(int X, int Y) {
    return X > -1 && X < N && Y > -1 && Y < M;
}
void Find(int X, int Y) {
    if (cMap[X][Y] != 0) return;
    cMap[X][Y] = 1;
    int Cnt = 0;
    for (int i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];
        Cnt += InMap(XX, YY) && Map[XX][YY] == 0 && cMap[XX][YY] == 0;
    }
    Map[X][Y] -= Cnt;
    Map[X][Y] = std::max(Map[X][Y], 0);
    for (int i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];

        if (InMap(XX, YY) && Map[XX][YY] != 0 && !cMap[XX][YY]) {
            Find(XX, YY);
        }
    }
}
int main() {
    int Cnt = 1, Cn = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", Map[i] + j);
        }
    }
    for (; Cnt == 1 ; ++Cn) {
        memset(cMap, 0, sizeof(cMap));
        Cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (Map[i][j] && !cMap[i][j]) {
                    ++Cnt;
                    Find(i, j);
                }
            }
        }
    }
    printf("%d", Cnt ? Cn - 1 : 0);
}
