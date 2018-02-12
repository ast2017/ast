#include <algorithm>
#include <cstdio>
int Ar[10];
int main() {
    int N, K, Cnt = 0;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d", Ar + i);
    std::sort(Ar, Ar + N);
    for (int i = N; i--; ) {
        for (; Ar[i] <= K; K -= Ar[i], ++Cnt) continue;
    }
    printf("%d", Cnt);
    return 0;
}
