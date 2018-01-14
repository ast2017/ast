#include<iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		char str[31] = "";
		fgets(str, 31, stdin);

		int sum = 0;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if ('A' <= str[j] && str[j] <= 'Z')
			{
				sum += (str[j] - 'A' + 1);
			}
		}

		if (sum == 100)
		{
			printf("PERFECT LIFE\n");
		}
		else
		{
			printf("%d\n", sum);
		}
	}
}
