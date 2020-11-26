#include <string>
#include <iostream>
#include <vector>
#include <Algorithm>
#include <queue>

//#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[201][201];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {

	// 큐 라이브러리 사용
	queue<pair<int, int>> q;
	q.push({ x,y });

	// 큐가 빌 때까지 반복하기 
	while (!q.empty()) {

		// 큐의 첫번째 요소 저장 후 삭제
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 현재 위치에서 4가지 방향으로의 위치 확인 (상하좌우)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 미로 찾기 공간을 벗어난 경우 무시
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			// 벽인 경우 무시
			if (graph[nx][ny] == 0)
				continue;

			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return graph[n - 1][m - 1];
}

int main(void) {

	cin >> n >> m;

	// 문자열로 쭉 입력받게 해서 한번에 입력하는 방법 중요
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
			graph[i][j] = temp[j] - '0';
	}

	cout << bfs(0, 0) << endl;

	return 0;
}