#include <algorithm>
#include <cstdio>
#include <vector>
std::vector < std::pair < int, int > > List;
int main() {
    int i, N, X, Y, Min = 987654321, Cnt = 1;
    scanf("%d", &N);
    for (i = N; i--; ) {
        scanf("%d%d", &X, &Y);
        List.push_back( std::pair < int, int > (X, Y) );
    }
    std::sort(List.begin(), List.end());
    Min = List[0].second;
    for (i = 1; i < N; ++i) {
        if (Min <= List[i].first) {
            Min = List[i].second;
            ++Cnt;
        }
        Min = std::min(Min, List[i].second);
    }
    printf("%d", Cnt);
}
