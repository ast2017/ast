#include <iostream>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int a[51] = { 0, };
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		int s;
		scanf("%d", &s);

		int p, m;
		for (int i = 0; i < n && s>0; i++)
		{
			p = m = -1; 
			for (int j = i, k = 0; j < n && k <= s; j++, k++)
			{
				if (m < a[j])
				{ 
					m = a[j];
					p = j;
				}
			}
			for (int j = p; j > i && s; j--)
			{ 
				int t = a[j]; 
				a[j] = a[j - 1]; 
				a[j - 1] = t; 
				s--; 
			}
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	return 0;
}
