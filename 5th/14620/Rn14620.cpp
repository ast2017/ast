#include <stdio.h>
#define MIN(x, y) (x < y ? x : y)
int N, Min = 987654321;
int Map[11][11], cMap[11][11];
int Dir_X[4] = { 1, 0, -1, 0 };
int Dir_Y[4] = { 0, 1, 0, -1 };
int IsPlant(int X, int Y) {
    int i;
    for (i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];
        if (cMap[XX][YY] == 1) return 0;
    }
    return 1;
}
void Make_cMap(int X, int Y) {
    int i;
    for (i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];
        cMap[XX][YY] = 1;
    }
    cMap[X][Y] = 1;
}
void Delete_cMap(int X, int Y) {
    int i;
    for (i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];
        cMap[XX][YY] = 0;
    }
    cMap[X][Y] = 0;
}
int CalcPlant(int X, int Y) {
    int i, Cnt = 0;
    for (i = 4; i--; ) {
        int XX = X + Dir_X[i];
        int YY = Y + Dir_Y[i];
        Cnt += Map[XX][YY];
    }
    return Cnt + Map[X][Y];
}
void Find(int I, int Cnt) {
    if (I == 0) {
        Min = MIN(Min, Cnt);
        return;
    }
    int i, j;
    for (i = 1; i < N - 1; ++i) {
        for (j = 1; j < N - 1; ++j) {
            if (IsPlant(i, j)) {
                Make_cMap(i, j);
                Find(I - 1, Cnt + CalcPlant(i, j));
                Delete_cMap(i, j);
            }
        }
    }
}
int main() {
    int i, j;
    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", Map[i] + j);
        }
    }
    Find(3, 0);
    printf("%d", Min);
    return 0;
}
