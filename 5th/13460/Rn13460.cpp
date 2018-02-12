#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
class NODE {
public:
    int rX, rY, bX, bY, Cnt;
};

char Map[11][11];
int rMap[11][11][11][11], Result = -1;
int Dir_X[4] = { 1, 0, -1, 0 };
int Dir_Y[4] = { 0, 1, 0, -1 };
void Move(int* X, int* Y, int x, int y, int Head) {
    int XX = *X + Dir_X[Head];
    int YY = *Y + Dir_Y[Head];
    if (Map[XX][YY] == '.' && !(XX == x && YY == y)) {
        *X = XX;
        *Y = YY;
        Move(X, Y, x, y, Head);
    } else if (Map[XX][YY] == 'O') {
        *X = -1;
        *Y = -1;
    }
}
/*void Find(int rX, int rY, int bX, int bY, int Cnt) {
    if (Flag | rMap[rX][rY]) return;
    int i;
    rMap[rX][rY] = 1;
    for (i = 4; i--; ) {
        int RX = rX, RY = rY, BX = bX, BY = bY;
        if (rX * Dir_X[i] + rY * Dir_Y[i] < bX * Dir_X[i] + bY * Dir_Y[i]) {
            printf("BB - I : %d / Cnt : %d\n", i, Cnt);
            Move(&BX, &BY, rX, rY, i);
            Move(&RX, &RY, BX, BY, i);
        } else {
            printf("RR - I : %d / Cnt : %d\n", i, Cnt);
            Move(&RX, &RY, bX, bY, i);
            Move(&BX, &BY, RX, RY, i);
        }
        if (RX == -1) {
            if (BX != -1) {
                Result = Cnt;
            } else {
                Result = -1;
            }
            Flag = 1;
            return;
        }
        if (!rMap[RX][RY]) {
            Find(RX, RY, BX, BY, Cnt + 1);
        }
    }
}*/
int main() {
    int i, j, N, M, _rX, _rY, _bX, _bY;
    std::queue < NODE > Pos;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            scanf(" %c", Map[i] + j);
            if (Map[i][j] == 'R') {
                _rX = i;
                _rY = j;
                Map[i][j] = '.';
            } else if (Map[i][j] == 'B') {
                _bX = i;
                _bY = j;
                Map[i][j] = '.';
            }
        }
    }
    Pos.push( { _rX, _rY, _bX, _bY, 1 } );
    for (; !Pos.empty(); ) {
        int rX = Pos.front().rX;
        int rY = Pos.front().rY;
        int bX = Pos.front().bX;
        int bY = Pos.front().bY;
        int Cnt = Pos.front().Cnt;
        Pos.pop();

        if (rMap[rX][rY][bX][bY]) continue;
        int i;
        rMap[rX][rY][bX][bY] = 1;
        for (i = 4; i--; ) {
            int RX = rX, RY = rY, BX = bX, BY = bY;
            if (rX * Dir_X[i] + rY * Dir_Y[i] < bX * Dir_X[i] + bY * Dir_Y[i]) {
                //printf("BB - I : %d / Cnt : %d / rx : %d / ry : %d / bx : %d / by : %d\n", i, Cnt, RX, RY, BX, BY);
                Move(&BX, &BY, rX, rY, i);
                Move(&RX, &RY, BX, BY, i);
                //printf(">> - I : %d / Cnt : %d / rx : %d / ry : %d / bx : %d / by : %d\n\n", i, Cnt, RX, RY, BX, BY);
            } else {
                //printf("RR - I : %d / Cnt : %d / rx : %d / ry : %d / bx : %d / by : %d\n", i, Cnt, RX, RY, BX, BY);
                Move(&RX, &RY, bX, bY, i);
                Move(&BX, &BY, RX, RY, i);
                //printf(">> - I : %d / Cnt : %d / rx : %d / ry : %d / bx : %d / by : %d\n\n", i, Cnt, RX, RY, BX, BY);
            }
            if (BX == -1) continue;
            if (RX == -1) {
                Result = std::min((Result == -1 ? 987654321 : Result), Cnt);
                break;
            }
            if (!rMap[RX][RY][BX][BY]) {
                Pos.push( { RX, RY, BX, BY, Cnt + 1 } );
            }
        }
    }

    //Find(rX, rY, bX, bY, 1);
    printf("%d", Result > 10 ? -1 : Result);
	return 0;
}
