#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting_time { int x, y; };
typedef meeting_time m_time;

bool cmp(const m_time &u, const m_time &v) {
	if(u.y < v.y) {
		return true;
	} else if(u.y == v.y) {
		return u.x < v.x;
	} else {
		return false;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<m_time> v(n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].x, &v[i].y);
	}
	sort(v.begin(), v.end(), cmp);

	int start, end, sol = 1;;
	start = v[0].x; end = v[0].y;
	
	for(int i = 1; i < v.size(); i++) {
		if(v[i].x >= end) {
			sol++;
			end = v[i].y;
		}
	}
	printf("%d\n", sol);

	return 0;
}