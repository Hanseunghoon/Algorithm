#include <string>
#include <iostream>
#include <vector>
#include <Algorithm>
#include <queue>

using namespace std;

int n, m;
int graph[201][201];

// �̵��� �� ���� ���� ���� (��, ��, ��, ��) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {

	// ť ���̺귯�� ���
	queue<pair<int, int>> q;
	q.push({ x,y });

	// ť�� �� ������ �ݺ��ϱ� 
	while (!q.empty()) {

		// ť�� ù��° ��� ���� �� ����
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// ���� ��ġ���� 4���� ���������� ��ġ Ȯ�� (�����¿�)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// �̷� ã�� ������ ��� ��� ����
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			// ���� ��� ����
			if (graph[nx][ny] == 0)
				continue;

			// �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	cout << bfs(0, 0);
}