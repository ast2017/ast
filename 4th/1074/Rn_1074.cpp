#include <stdio.h>
int Cnt, R, C;
void Find(int X, int Y, int XX,int YY) {
    int Xmid = (X + XX) / 2;
    int Ymid = (Y + YY) / 2;

    if (XX - X < 2) {
        if (R == X && C == Y) printf("%d", Cnt);
        ++Cnt;
        if (R == X && C == Y + 1) printf("%d", Cnt);
        ++Cnt;
        if (R == X + 1 && C == Y) printf("%d", Cnt);
        ++Cnt;
        if (R == X + 1 && C == Y + 1) printf("%d", Cnt);
        ++Cnt;
    }
    else {
        Find(X, Y, Xmid, Ymid);
        Find(X, Ymid + 1, Xmid, YY);
        Find(Xmid + 1, Y, XX, Ymid);
        Find(Xmid + 1, Ymid + 1, XX, YY);
    }
}
int main()
{
    int N;
    scanf("%d%d%d", &N, &R, &C);
    N = pow(2, N);
    Find(0, 0, N - 1, N - 1);
    return 0;
}
