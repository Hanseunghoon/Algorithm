#include <string>
#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

int n, m, res = 0;
vector<int> visited(1000);
vector<vector<int>> graph(1000);

// DFS �Լ� ����
void dfs(int x) {
	// ���� ��带 �湮 ó��
	visited[x] = true;
	res++;
	cout << x << ' ';
	// ���� ���� ����� �ٸ� ��带 ��������� �湮
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y])
			dfs(y);
	}
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
	}

	dfs(0);

	cout << res;
}