#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int a[101][101];
int n;
queue<pii> s[10001];

void colorArea(int color, int x, int y)
{
	bool check[101][101] = { false, };
	check[x][y] = true;
	a[x][y] = color;

	queue<pii> q;
	q.push(pii(x, y));

	while (!q.empty())
	{
		pii front = q.front();
		q.pop();

		int ax[] = { 1, -1, 0, 0 };
		int ay[] = { 0, 0, 1, -1 };

		bool surface = false;
		for (int i = 0; i < 4; i++)
		{
			int tx = front.first + ax[i];
			int ty = front.second + ay[i];

			if (tx < 1 || n < tx || ty < 1 || n < ty) continue;
			if (check[tx][ty] == true) continue;
			if (a[tx][ty] == 0 && surface == false)
			{
				s[color].push(front);
				surface = true;
				continue;
			}
			if (a[tx][ty] != -1) continue;

			check[tx][ty] = true;
			a[tx][ty] = color;
			q.push(pii(tx, ty));
		}
	}
}

int spreadColor(int color)
{
	int size = s[color].size();

	bool check[101][101] = { false, };

	int max = 2;
	while (size--)
	{
		pii front = s[color].front();
		s[color].pop();

		int ax[] = { 1, -1, 0, 0 };
		int ay[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int tx = front.first + ax[i];
			int ty = front.second + ay[i];

			if (tx < 1 || n < tx || ty < 1 || n < ty) continue;
			if (check[tx][ty] == true) continue;
			if (a[tx][ty] == color) continue;
			if (a[tx][ty] == 0)
			{
				check[tx][ty] = true;
				s[color].push(pii(tx, ty));
				a[tx][ty] = color;
				continue;
			}

			if (a[tx][ty] < color)
			{
				if (max > 1)
				{
					max = 1;
				}
			}
			else
			{
				if (max > 0)
				{
					max = 0;
				}
			}
		}
	}

	return max;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) a[i][j] = -1;
		}
	}

	int color = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == -1)
			{
				colorArea(color++, i, j);
			}
		}
	}

	int count = 0;
	bool escape = false;
	while (true)
	{
		int max = 2;
		for (int i = 1; i < color; i++)
		{
			int retval = spreadColor(i);
			if (retval != 2)
			{
				if (retval < max)
				{
					max = retval;
				}
				escape = true;
			}
		}

		if (escape == true)
		{
			count += max;
			break;
		}
		count += 2;
	}

	printf("%d\n", count);
	
	return 0;
}
