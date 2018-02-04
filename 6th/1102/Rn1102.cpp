#include <stdio.h>
#include <string.h>
//#define MIN(I, J) (I < J ? I : J)
#define MAX(I, J) (I > J ? I : J)
#define INF 987654321
int N, Map[16][16], DP[65536], Mn[16];
int MIN(int I, int J) {
   return I < J ? I : J;
}
int Find(int J, int K, int C) {
   if (!C) return 0;
   if (DP[J] != -1) return DP[J];
   DP[J] = INF;
   int Bit = J & ((1 << N) - 1), i, j, Tmp[16];
   memmove(Tmp, Mn, sizeof(Tmp));
   for (j = 0; j < N; ++j) {
      Mn[j] = MIN(Mn[j], Map[K][j]);
   }
   for (i = 0; i < N; ++i, Bit >>= 1) {
      if (!(Bit & 1)) {
         DP[J] = MIN(DP[J], Find(J + (1 << i), i, C - 1) + Mn[i]);
      }
   }
   memmove(Mn, Tmp, sizeof(Tmp));
   return DP[J];
}
int main() {
   char Set[17];
   int i, j, Min = INF, P, Cnt = 0, J = 0, Flag = -1;
   scanf("%d", &N);
   memset(DP, -1, sizeof(DP));
   for (i = 0; i < N; ++i) {
      for (j = 0; j < N; ++j) {
         scanf("%d", Map[i] + j);
         if (i == j) Map[i][j] = INF;
         //Map[i][j] = Map[i][j] + !Map[i][j] * INF;
      }
   }
   getchar();
   gets(Set);
   scanf("%d", &P);
   for (i = 0; i < N; ++i) {
      Mn[i] = INF;
   }
   for (i = 0; i < N; ++i) {
      if (Set[i] == 'Y') {
         ++Cnt;
         Flag = i;
         J += 1 << i;
         for (j = 0; j < N; ++j) {
            Mn[j] = MIN(Mn[j], Map[i][j]);
         }
      }
   }
   if (Flag != -1) Min = Find(J, Flag, MAX(P - Cnt, 0));
   printf("%d", Min == INF ? P == 0 ? 0 : -1 : Min);
   return 0;
}
