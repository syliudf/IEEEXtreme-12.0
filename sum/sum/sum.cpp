#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct cand
{
	int value;
	int ser;
}cand;
//cand test[100];
cand d[20010];
bool cmpare(const cand &a, const cand &b)            //const必须加，不然会错，目前不懂为啥。当return的是ture时，a先输出，所以示例中是升序
{
	return a.value < b.value;
}
int binarySearch2( int low, int high, int target) {
	int middle = 0;
	while (low < high) {
		middle = (low + high) / 2;
		if (target == d[middle].value) {
			return middle;
		}
		else if (target < d[middle].value) {
			high = middle;
		}
		else if (target > d[middle].value) {
			low = middle + 1;
		}
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (t--) 
    {
		int sum, length;
		cin >> sum >> length;
		if (sum == 0 && length == 0)
		{
			printf("!OK\n"); continue;
		}
		for (int i = 0; i < length; i++)
		{
			scanf("%d", &d[i].value);
			d[i].ser = i;

		}
		sort(d, d + length, cmpare);

		int flag = 0;
		int min_num = length + 1;
		int min_ans[2];
		for (int i = 0; i < length; i++)
		{
			int temp;
			temp = binarySearch2(i + 1, length, sum - d[i].value);
			if (temp != -1)
			{
				flag = 1;
				if (min_num > max(d[i].ser, d[temp].ser))
				{
					min_num = max(d[i].ser, d[temp].ser);
					if (d[i].value < d[temp].value)
					{
						min_ans[0] = d[i].value;
						min_ans[1] = d[temp].value;
					}
					else
					{
						min_ans[1] = d[i].value;
						min_ans[0] = d[temp].value;
					}
				}
			}

			//binary_search（ after + i + 1, after + length, sum - after[i]）;
	//		cout << d[i].value << d[i].ser<<endl
			;
			//d[i].ser = i;

		}
		if (flag == 0)printf("!OK\n");
		else printf("%d %d\n", min_ans[0], min_ans[1]);
	}
	return 0;

}
