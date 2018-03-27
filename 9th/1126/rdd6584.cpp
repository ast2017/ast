/* version 1
DP[순서][두 탑간 차이] = 왼쪽탑의 높이로 정의.
오른쪽 탑이 더 높아서 음수로 변하는 경우는
일괄적으로 25만을 더해서 음수를 없애는 방법으로 해결가능.
그리고 오른쪽이 더 높은경우, 왼쪽탑과 오른쪽탑의 구성 요소를
서로 교환하는 것으로도 해결가능하다.
*/
#include <cstdio>
#include <memory.h>
using namespace std;

int vec[50];
int dp[50][500001];
int n;

int go(int o, int ck) {
	if (ck < 0 || ck > 500000) return -4567456;
	if (o == n) {
		if (ck == 250000) return 0;
		else return -4567456;
	}
	if (dp[o][ck] != -1) return dp[o][ck];

	int c1, c2, c3;
	c1 = go(o + 1, ck + vec[o]) + vec[o];
	c2 = go(o + 1, ck - vec[o]);
	c3 = go(o + 1, ck);

	return dp[o][ck] = c1 > c2 ? (c1 > c3 ? c1 : c3) : (c2 > c3 ? c2 : c3);
}

int main() {
	int t;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	memset(dp, -1, sizeof(dp));

	t = go(0, 250000);

	if (t <= 0) printf("-1");
	else printf("%d", t);
}

// Cubelover님 버전 반복문.
#include <cstdio>
#include <memory.h>
using namespace std;

int dp[2][500001];
int n;

int main() {
	int val, *p = dp[0], *q = dp[1], *t;
	scanf("%d", &n);

	for (int i = 0; i < 500001; i++)
		p[i] = -1e+8;
	p[250000] = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		
		for (int j = 500000; j >= 0; j--) {
			q[j] = p[j];
			if (j + val < 500001 && q[j] < p[j + val] + val) q[j] = p[j + val] + val;
			if (j >= val && q[j] < p[j - val]) q[j] = p[j - val];
		}

		t = p;
		p = q;
		q = t;
	}

	printf("%d", p[250000] ? p[250000] : -1);
}