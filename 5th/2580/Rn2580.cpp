#include <bits/stdc++.h>
using namespace std;
int Map[10][10], PosX[100], PosY[100], Cnt;
bool Left[10][10], Up[10][10], Sqr[10][10], Flag = 1;
void Find(int N) {
    if (Cnt == N) {
        Flag = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << Map[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    bool Num[10];
    for (int i = 1; i < 10; ++i) {
        Num[i] = Left[PosX[N]][i] || Up[PosY[N]][i] || Sqr[3 * (PosX[N] / 3) + PosY[N] / 3][i];
    }
    for (int i = 1; i < 10; ++i) {
        if (!Num[i]) {
            Map[PosX[N]][PosY[N]] = i;
            Left[PosX[N]][i] = Up[PosY[N]][i] = Sqr[3 * (PosX[N] / 3) + PosY[N] / 3][i] = 1;
            if (Flag) Find(N + 1);
            Map[PosX[N]][PosY[N]] = 0;
            Left[PosX[N]][i] = Up[PosY[N]][i] = Sqr[3 * (PosX[N] / 3) + PosY[N] / 3][i] = 0;
        }
    }
}
int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> Map[i][j];
            if (!Map[i][j]) {
                PosX[Cnt] = i;
                PosY[Cnt++] = j;
            } else {
                Left[i][Map[i][j]] = 1;
                Up[j][Map[i][j]] = 1;
                Sqr[3 * (i / 3) + j / 3][Map[i][j]] = 1;
            }
        }
    }
    Find(0);
    return 0;
}
