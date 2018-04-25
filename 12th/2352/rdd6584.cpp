#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
const ll MOD = 1e9 + 7;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v; queue<int> q; deque<int> dq;

int main() {
	int n, temp, l, r, mid;
	scanf("%d", &n);

	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (v.back() < temp) v.push_back(temp);
		else {
			l = 0, r = sz(v);
			while (l <= r) {
				mid = (l + r) / 2;
				if (v[mid] >= temp) r = mid - 1;
				else l = mid + 1;
			}
			v[l] = temp;
		}
	}
	printf("%d", sz(v) - 1);
}