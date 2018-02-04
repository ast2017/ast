#include <stdio.h>
#define Min(x, y) (x < y ? x : y)
long long int Len[100001];
long long int Cost[100001];
int main() {
    long long int i, N, M = 0, cM = 987654321;
    scanf("%lld", &N);
    for (i = 0; i < N - 1; ++i) {
        scanf("%lld", Len + i);
    }
    for (i = 0; i < N; ++i) {
        scanf("%lld", Cost + i);
    }
    for (i = 0; i < N - 1; ++i) {
        cM = Min(cM, Cost[i]);
        M += cM * Len[i];
    }
    printf("%lld", M);
}
