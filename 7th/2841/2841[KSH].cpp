#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
std::vector<int> v[6];
int main() {
	int n, fret, cnt = 0;
	scanf("%d %d", &n, &fret);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(v[a].empty() || v[a].back() < b) {
			cnt++;
			v[a].push_back(b);
			continue;
		}
		while(!v[a].empty() && v[a].back() > b) {
			cnt++;
			v[a].pop_back();
			if(v[a].empty()) {
				v[a].push_back(b);
				cnt++;
				break;
			} else if(v[a].back() < b) {
				v[a].push_back(b);
				cnt++;
				break;
			}		
		}
	}
	return 0;
}