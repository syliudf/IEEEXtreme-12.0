#include <iostream>
#include <vector> 
#include <tuple>
#include <stack>
#include <map>
using namespace std;

int V, E;

//带权有向图
map<int, vector<tuple<int, int, double>>> EWD;

bool marked[100];   // v 是否已经被访问过？
bool onStack[100];  // v 是否在栈里？
tuple<int, int, double> edgeTo[100]; // 到达顶点 v 的最后一条边
stack<tuple<int, int, double>> cycle; // 有向环


void dfs(int v) {
	onStack[v] = true;
	marked[v] = true;

	for (vector<tuple<int, int, double>>::iterator ii = EWD[v].begin(); ii != EWD[v].end(); ii++)
	{

		int w = get<1>(*ii);

		if (!cycle.empty()) {    // 已经找到了一个有向环
			return;
		}
		else if (!marked[w]) {   // 遇见没访问过的顶点继续dfs递归
			edgeTo[w] = *ii;
			dfs(w);
		}
		else if (onStack[w]) {   // 遇见一个访问过的顶点，并且该顶点在栈里说明发现了一个新环
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
