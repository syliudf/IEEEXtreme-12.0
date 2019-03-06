#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<cstring>

using namespace std;
typedef struct line
{
	int s;
	int f;
	int w;
};line dp[10010];


bool cmpare(const line &a, const line  &b)           
{
	return a.f < b.f;
}

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &dp[i].s, &dp[i].f, &dp[i].w);
	}

	sort(dp, dp + n, cmpare);
	int p[10010];
	memset(p, 0, sizeof(p));
	int f[10010];
	for (int i = 0; i < n; i++)
	{
		f[i] = dp[i].f;
	//	cout << f[i] << " ";
	}
	//cout << endl;
	for (int i = 0; i < n; i++)
	{
		p[i]=lower_bound(f, f + n, dp[i].s)-f-1;
		if (p[i] == -1)p[i] = 0;

	//	cout << p[i] << " ";

	}
	//cout << endl;
	//for()

	int max_indx=0;
	int max_w=dp[0].w;
	for (int i = 0; i < n; i++)
	{
		if (max_w <= dp[i].w)
		{
			max_w = dp[i].w;
			max_indx = i;
		}
			
	}
/*	int ena[1010];
	int tm[10010];
	memset(ena, 0, sizeof(ena));
	memset(tm, 0, sizeof(tm));
	for (int i = 0; i < n; i++)
	{
		int last_f = -1;
		if (max_w == dp[i].w && last_f<dp[i].s)
		{
			for (int j = dp[i].s; j <= dp[i].f; j++)ena[j] = 1;
			last_f = dp[i].f;
			tm[i] = 1;
		}
	}*/
	//for (int k = 0; k < 20; k++)cout << ena[k] << " ";
	//cout << endl;
	int opt[10010];
	memset(opt, 0, sizeof(opt));
	opt[0] = dp[0].w;
	for (int i = 1; i < n; i++)
	{
		int opt_last;
		if (p[i] >= 0) {
			opt_last = opt[p[i]];
		}
		else opt_last = 0;
		/*if (dp[i].w == max_w && tm[i])
			opt[i] = dp[i].w + opt_last;
		else if(ena[dp[i].s]==1 or ena[dp[i].f]==1)
			opt[i] = opt[i-1];
		else opt[i] = max(dp[i].w + opt_last, opt[i - 1]);*/
		opt[i] = max(dp[i].w + opt_last, opt[i - 1]);
	}
	//for (int i = 0; i < n; i++)cout << opt[i] << " ";
	//cout << endl;
	cout << opt[n - 1];
	//
	return 0;
}