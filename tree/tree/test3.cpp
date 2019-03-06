#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char TF[27];
char TM[27];
int depth[27];
char dis[27][27];
void TL(int p1, int p2, int q1, int q2, int root, int d)
{
	if (p1 > p2) return;
	for (root = q1; TM[root] != TF[p1]; ++root);
	depth[root] = d;



	TL(p1 + 1, p1 + root - q1, q1, root - 1,0, d+1);
	TL(p1 + root - q1 + 1, p2, root + 1, q2,0, d+1);
	//cout << TM[root];
}

int main()
{

	int flag = 1;
	while (cin >> TM >> TF) {
		if (flag == 0)cout << endl;
		else flag = 0;
		int max_d = 0;
		int L = strlen(TF) - 1;
		memset(depth, 0, sizeof(depth));
		TL(0, L, 0, L, 0, 0);
		for (int i = 0; i <L+1; i++)
		{
	//	cout << depth[i];
			if (depth[i] > max_d)max_d = depth[i];
		}
	//	cout << endl<<max_d<<endl;
		memset(dis,' ' , sizeof(dis));
		for (int i = 0; i < L + 1; i++)
			dis[depth[i]][i] = TM[i];
		for (int i = 0; i <= max_d; i++)

		{
			for (int j = 0; j < L + 1; j++)
			{
				printf("%c", dis[i][j]);
			}
			if(i!=max_d)cout << endl;
		}
		//cout << endl;
	}
	return 0;
}
