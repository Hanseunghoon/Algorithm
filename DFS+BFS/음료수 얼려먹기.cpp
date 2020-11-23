#include <string>
#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

int n, m, res = 0;
vector<int> visited(1000);
vector<vector<int>> graph(1000);

// DFS 함수 정의
void dfs(int x) {
	// 현재 노드를 방문 처리
	visited[x] = true;
	res++;
	cout << x << ' ';
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
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