#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string &str, const string &str2) {
	return str < str2;
}

int solve(int n, vector<string> &v) {
	int cmp_count = 0;
	for(int i = 0; i < n; i++) {
		int nc = v[i].size();
		for(int j = i; j < n; j++) {
			if(i == j) continue;
			for(int k = 0; k < nc; k++) {
				if(v[i][k] == v[j][k]) {
					cmp_count = 1;
				} else if(v[i][k] != v[j][k]) {
					cmp_count = 0;
					break;
				}
			}
			if(cmp_count == 1) {
				v.clear();
				return cmp_count;
			}
				
		}
	}
	v.clear();
	return cmp_count;
}

int main() {
	vector<string> v;
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end(), cmp);
		printf("%s\n", solve(n, v) == 1 ? "NO" : "YES");
	}
	return 0;
}