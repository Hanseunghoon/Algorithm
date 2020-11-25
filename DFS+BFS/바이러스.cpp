#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res = 0;
vector<int> visited(101);
vector<vector<int>> graph(101);

// DFS 함수 정의
void dfs(int x) {
	// 현재 노드를 방문 처리
	visited[x] = true;
	//ut << x << '->';
	
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]){
			res++;
			dfs(y);
		}
	}
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	cout << res;
}
