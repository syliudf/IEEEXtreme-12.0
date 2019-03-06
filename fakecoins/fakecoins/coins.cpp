#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int ls[10][26], rs[10][26];
int uneq[26][26][10];
int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	int n, m, x;

	int vec[26];
	int sum;
	scanf("%d,%d", &n, &m);
	memset(ls, 0, sizeof(ls));
	memset(uneq, 0, sizeof(uneq));
	getchar();
	for (int i = 0; i < m; i++)
	{
		//char c;
		char a[60];
		int h = 0;
		cin >> a;
		int j=0;
		while (a[j] != '-')
		{
			ls[i][a[j] - 'A'] = 1;
			j++;
		}
		j++;
		while (a[j] >= 'A'&&a[j] <= 'Z')
		{
			ls[i][a[j] - 'A'] -= 1;
			j++;
		}
		/*c = getchar();
		while (c != '-')
		{
			ls[i][c - 'A'] = 1;
			c = getchar();
			h++;
		}
		while (h--)
		{
			c = getchar();
			ls[i][c - 'A'] -= 1;
		}*/
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			memset(vec, 0, sizeof(vec));
			vec[i] = 1;
			vec[j] = 1;
			for (int k = 0; k < m; k++)
			{
				sum = 0;
				for (int l = 0; l < n; l++)
				{
					sum += vec[l] * ls[k][l];
				}
				if (sum > 0)uneq[i][j][k] = 1;
				else if (sum < 0)uneq[i][j][k] = -1;
			}

		}
	}

	for (int i1 = 0; i1 < n; i1++)
	{
		for (int j1 = i1 + 1; j1 < n; j1++)
		{
			for (int i2 = i1; i2 < n; i2++)
			{
				int j2_tmp;
				if (i1 == i2)
				{
					j2_tmp = j1 + 1;
				}
				else j2_tmp = i2 + 1;

				for (int j2 = j2_tmp;j2 < n; j2++)
				{
					int flag = 1;
					for (int k = 0; k < m; k++)
					{
						if (uneq[i1][j1][k] != uneq[i2][j2][k])flag = 0;
					}
					if (flag == 1)printf("%c%c=%c%c\n", i1 + 'A', j1 + 'A', i2 + 'A', j2 + 'A');
				}
			}
		}
	}
	//system("pause");
	return 0;
}