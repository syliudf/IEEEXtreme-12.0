#include <iostream>
#include <vector> 
#include <tuple>
#include <stack>
#include <map>
using namespace std;

int V, E;

//��Ȩ����ͼ
map<int, vector<tuple<int, int, double>>> EWD;

bool marked[100];   // v �Ƿ��Ѿ������ʹ���
bool onStack[100];  // v �Ƿ���ջ�
tuple<int, int, double> edgeTo[100]; // ���ﶥ�� v �����һ����
stack<tuple<int, int, double>> cycle; // ����


void dfs(int v) {
	onStack[v] = true;
	marked[v] = true;

	for (vector<tuple<int, int, double>>::iterator ii = EWD[v].begin(); ii != EWD[v].end(); ii++)
	{

		int w = get<1>(*ii);

		if (!cycle.empty()) {    // �Ѿ��ҵ���һ������
			return;
		}
		else if (!marked[w]) {   // ����û���ʹ��Ķ������dfs�ݹ�
			edgeTo[w] = *ii;
			dfs(w);
		}
		else if (onStack[w]) {   // ����һ�����ʹ��Ķ��㣬���Ҹö�����ջ��˵��������һ���»�
			tuple<int, int, double> f = *ii;
			while (get<0>(f) != w) {
				cycle.push(f);
				f = edgeTo[get<0>(f)];
			}

			cycle.push(f);
			return;

		}
	}

	onStack[v] = false;
}

void readData() {
	cin >> E;
	for (int i = 0; i < E; i++)
	{
		int v, w;
		double weight;
		cin >> v >> w >> weight;
		EWD[v].push_back(make_tuple(v, w, weight));
	}
}

void showData() {
	cout << "EdgeWeightedDigraph : " << endl;
	for (int v = 0; v < V; v++)
	{
		cout << v << " : ";
		for (vector<tuple<int, int, double>>::iterator ii = EWD[v].begin(); ii != EWD[v].end(); ii++)
			cout << get<0>(*ii) << "->" << get<1>(*ii) << " " << get<2>(*ii) << "  ";
		cout << endl;
	}

	system("pause");
}

int main()
{
	readData();
	showData();

	//findCycle();
	//showCycle();

}
