#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string &str, const string &str2) {
	return str < str2;
}

int solve(int n, vector<string> &v) {
	for(int i = 0; i < n - 1; i++) {
		if(v[i] == v[i + 1].substr(0, v[i].length())) {
			return 1;
		}
	}
	return 0;
}

int main() {
	vector<string> v;
	int t; 
	cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end(), cmp);
		if(solve(n, v)) cout << "NO" << '\n';
		else cout << "YES" << '\n';
		v.clear();
	}
	return 0;
}