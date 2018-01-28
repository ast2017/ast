#include <iostream>
using namespace std;

int a[100001];

int main()
{
	int n;
	scanf("%d", &n);

	a[0] = 1;
	a[1] = 3;
	for (int i = 2; i <= n; i++)
	{
		a[i] = (a[i - 2] + a[i - 1] * 2) % 9901;
	}

	printf("%d\n", a[n]);

	return 0;
}
