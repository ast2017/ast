#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main(){
	
	int t = 0;
	scanf("%d", &t);

	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
        vector<string> v;
		for (int i = 0; i < n; i++)
		{
			char phone[11] = "";
			scanf("%s", phone);
			v.push_back(phone);
		}

		sort(v.begin(), v.end());	// nlogn
		
		for (int i = 0; i < n-1; i++)
		{
			int len = v[i].length();
			char temp[11] = "";
			strcpy(temp, v[i + 1].c_str());

			temp[len] = '\0';

			if (strcmp(v[i].c_str(), temp) == 0)
			{
				n = -1;
				printf("NO\n");
			}
		}

		if (n != -1)
		{
			printf("YES\n");
		}
	}
	return 0;
}
