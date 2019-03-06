#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<cstdlib>
#include<stack>


//#define MAX_N 2002
using namespace std;

int main()
{
	stack<char> s1, s2;
	//cout << "impossible" << endl;
	char a[40];
	int s;
	cin >> a;
	s = strlen(a);
	if (s % 4 != 0)cout << "impossible" << endl;
	else
	{
		int r = 0;
		int sq = 0;
		for (int i = 0; i < s; i++)
		{
			if (a[i] == '(')r++;
			if (a[i] == ')')r--;
			if (a[i] == '[')sq++;
			if (a[i] == ']')sq--;

			if (r < 0 || sq < 0)
			{
				cout << "impossible" << endl;
				return 0;
			}
		}
		int key = 0;
		int d[40];
		memset(d, 0, sizeof(d));
		int max_l = s / 4;
		int left1 = 0;
		int left2 = 0;
		while (key <= s)
		{
		}


	}
	//cout << a;
	//system("pause");
	return 0;
}