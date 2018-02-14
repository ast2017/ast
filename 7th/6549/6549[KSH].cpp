#include <cstdio>
#include <stack>
#include <algorithm>
int n;
typedef long long ll;
void sol() {
	while(scanf("%d", &n) == 1) {
		if(n == 0) return;

		int i = 0;
		ll ans = 0;
		int a[100001];
		std::stack<ll> s;

		for(i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		s.push(-1);
		for(i = 0; i < n; i++) {
			while(!s.empty() && a[s.top()] > a[i]) {
				int idx = s.top(); s.pop();
				if(!s.empty())
					ans = std::max(ans, a[idx] * (i - s.top() - 1));
			}
			s.push(i);
		}
		while(!s.empty()) {
			int idx = s.top(); s.pop();
			if(!s.empty())
				ans = std::max(ans, a[idx] * (i - s.top() - 1));
		}
		printf("%lld\n", ans);
	}
}
int main() {
	sol();
	return 0;
}