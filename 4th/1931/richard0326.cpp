#include <iostream>
#include <algorithm>
using namespace std;

typedef struct pair
{
	int start;
	int end;
} mPair;

mPair a[100001];

bool compare(mPair a, mPair b)
{
	if (a.end < b.end)
	{
		return true;
	}
	else if (b.end == a.end)
	{
		if (a.start < b.start)
		{
			return true;
		}
	}

	return false;
}

int main() 
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].start, &a[i].end);
	}

	sort(a, a + n, compare);

	int prev = 0;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[prev].end <= a[i].start)
		{
			ans++;
			prev = i;
		}
	}

	printf("%d\n", ans);

	return 0;
}
