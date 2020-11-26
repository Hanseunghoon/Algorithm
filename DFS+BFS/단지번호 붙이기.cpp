#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int visited[25][25];	// visited는 항상 원 배열과 같은 형태로
int graph[25][25];
vector<int> res;
int tmp = 0;

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };	

void dfs(int x, int y) {

	tmp++;	// dfs함수 호출 수 = 탐색한 1의 개수
	visited[x][y] = true;
	
	// 현재 위치에서 4가지 방향으로의 위치 확인 (상하좌우)
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 공간을 벗어난 경우 무시
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		// 0인 경우 무시
		if (graph[nx][ny] == 0)
			continue;

		// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
		if (graph[nx][ny] == 1 && visited[nx][ny] == false) {
			dfs(nx, ny);
		}
	}	
}

int main(void) {

	cin >> n;

	// 문자열로 쭉 입력받게 해서 한번에 입력하는 방법 중요
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)	
			graph[i][j] = temp[j] - '0';
	}
	
	// 전체 배열 중에 1을 만나면 dfs (1만난 수 = 단지 수 = res.size)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 1인데 visit하지 않은 곳이면 dfs
			if (graph[i][j] == 1 && visited[i][j] == false) {
				tmp = 0;
				dfs(i, j);
				// 탐색해서 1 발견한 수 = dfs함수 재귀한만큼
				res.push_back(tmp);
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++) 
		cout << res[i] << endl;
}
