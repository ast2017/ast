#include <bits/stdc++.h>
using namespace std;
bool Cmap[9][9][10], Visited[10][10], Left[10][10], Up[10][10], Box[10][10], Flag;
int Map[9][9];
int Dir_X[4] = { 1, 0, -1, 0 };
int Dir_Y[4] = { 0, 1, 0, -1 };
inline bool InMap(int X, int Y) {
    return X > -1 && X < 9 && Y > -1 && Y < 9;
}
void Find(int I, vector < pair < int, int > >& List) {
    if (Flag) return;
    if (I == List.size()) {
        Flag = 1;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d", Map[i][j]);
            }
            puts("");
        }
    }
    int X = List[I].first;
    int Y = List[I].second;
    if (Map[X][Y] != -1) {
        Find(I + 1, List);
    } else {
        for (int i = 1; i < 10; ++i) {
            for (int j = 1; j < 10; ++j) {
                if (i == j || Visited[i][j] || Left[X][i] || Up[Y][i] || Cmap[X][Y][i]) continue;
                Cmap[X][Y][i] = Visited[j][i] = Visited[i][j] = Left[X][i] = Up[Y][i] = 1;
                Map[X][Y] = i;
                for (int Di = 4; Di--; ) {
                    int XX = X + Dir_X[Di];
                    int YY = Y + Dir_Y[Di];

                    if (InMap(XX, YY) && Map[XX][YY] == -1 && !Left[XX][j] && !Up[YY][j] && !Cmap[XX][YY][j]) {
                        Map[XX][YY] = j;
                        Left[XX][j] = Up[YY][j] = Cmap[XX][YY][j] = 1;
                        Find(I + 1, List);
                        Cmap[XX][YY][j] = Left[XX][j] = Up[YY][j] = 0;
                        Map[XX][YY] = -1;
                    }
                }
                Cmap[X][Y][i] = Visited[j][i] = Visited[i][j] = Left[X][i] = Up[Y][i] = 0;
                Map[X][Y] = -1;
            }
        }
    }
}
int main() {
    for (int Puzzle = 1; ; ++Puzzle) {
        vector < pair < int, int > > List;
        char LU[3], LV[3];
        int N, U, V;
        scanf("%d", &N);
        if (N == 0) break;

        memset(Map, -1, sizeof(Map));
        memset(Visited, 0, sizeof(Visited));
        memset(Left, 0, sizeof(Left));
        memset(Up, 0, sizeof(Up));
        memset(Box, 0, sizeof(Box));
        memset(Cmap, 0, sizeof(Cmap));
        Flag = 0;

        for (int i = N; i--; ) {
            scanf("%d %s %d %s", &U, LU, &V, LV);
            Map[LU[0] - 'A'][LU[1] - '1'] = U;
            Map[LV[0] - 'A'][LV[1] - '1'] = V;
            Left[LU[0] - 'A'][U] = Left[LV[0] - 'A'][V] = Up[LU[1] - '1'][U] = Up[LV[1] - '1'][V] = 1;
            Visited[U][V] = Visited[V][U] = 1;
        }
        for (int i = 9; i--; ) {
            scanf("%s", LU);
            Map[LU[0] - 'A'][LU[1] - '1'] = 9 - i;
            Left[LU[0] - 'A'][9 - i] = Up[LU[1] - '1'][9 - i] = 1;
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(Map[i][j] == -1) List.push_back( pair < int, int > (i, j));
            }
        }
        printf("Puzzle %d\n", Puzzle);
        Find(0, List);
    }
    return 0;
}
