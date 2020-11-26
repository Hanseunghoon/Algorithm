#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 51

int graph[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { false, };
int testcase;
int n, m, k;

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;

		if (graph[nx][ny] == 1 && !visit[nx][ny]) {
			visit[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {

	cin >> testcase;

	while (testcase--)
	{
		int cnt = 0;
		memset(graph, 0, sizeof(graph));		// 다시 0으로 초기화
		memset(visit, false, sizeof(visit));	// 다시 0으로 초기화

		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			graph[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == 1 && !visit[i][j]) {
					cnt++;
					visit[i][j] = true;
					dfs(i, j);
				}
			}
		}

		cout << cnt << endl;
	}
	return 0;
}