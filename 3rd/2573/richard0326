#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n;
int m;

int ice[301][301];
bool check[301][301];
queue<pii> q;
queue<pii> c;

int melt()
{
	int time = 1;
	while (true)
	{
		int size = q.size();

		while (size--)
		{
			pii front = q.front();
			q.pop();

			int ax[] = { 1, -1, 0, 0 };
			int ay[] = { 0, 0, 1, -1 };
			
			for (int i = 0; i < 4; i++)
			{
				int tx = front.first + ax[i];
				int ty = front.second + ay[i];

				if (tx < 0 || n <= tx) continue;
				if (ty < 0 || m <= ty) continue;
				if (ice[tx][ty] != 0) continue;
				if (check[tx][ty] == true) continue;

				ice[front.first][front.second]--;
				if (ice[front.first][front.second] == 0)
				{
					break;
				}
			}

			if (ice[front.first][front.second] != 0)
			{
				q.push(pii(front.first, front.second));
			}
			else
			{
				c.push(pii(front.first, front.second));
			}
		}

		size = c.size();
		while (size--)
		{
			pii front = c.front();
			c.pop();

			check[front.first][front.second] = false;
		}

		if (q.empty() == true)
		{
			break;
		}

		pii front = q.front();
		size = q.size();

		queue<pii> p;
		p.push(front);
		bool tcheck[301][301] = { false, };
		int count = 0;
		while (!p.empty())
		{
			pii front = p.front();
			p.pop();
			count++;
			tcheck[front.first][front.second] = true;

			int ax[] = { 1, -1, 0, 0 };
			int ay[] = { 0, 0, 1, -1 };

			for (int i = 0; i < 4; i++)
			{
				int tx = front.first + ax[i];
				int ty = front.second + ay[i];

				if (tx < 0 || n <= tx) continue;
				if (ty < 0 || m <= ty) continue;
				if (ice[tx][ty] == 0) continue;
				if (tcheck[tx][ty] == true) continue;
				
				tcheck[tx][ty] = true;
				p.push(pii(tx, ty));
			}
		}

		if (count != size)
		{
			return time;
		}
		time++;
	}

	// 끝까지 한 덩어리인 경우
	return 0;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &ice[i][j]);
			if (ice[i][j] != 0)
			{
				q.push(pii(i, j));
				check[i][j] = true;
			}
		}
	}

	printf("%d\n", melt());

	return 0;
}
