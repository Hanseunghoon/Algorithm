#include <iostream>
#include <algorithm>

using namespace std;

int n, m, res;
int arr[8][8];	// 초기 맵 배열
int temp[8][8]; // 벽을 설치한 뒤의 맵 배열

// 4가지 이동 방향에 대한 배열
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 바이러스 확산(DFS)
void virus(int x, int y)
{

	// 4방향으로 퍼질 수 있는 경우 확산
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 더 이상 갈 수 없는 곳 제외 바이러스 감염(2)
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

// 안전 영역 계산
int getScore()
{
	int score = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
			{
				score += 1;
			}
		}
	}

	return score;
}

// 울타리 설치 및 안전 영역 계산(DFS)
void dfs(int count)
{

	// 울타리가 총 3개 설치된 경우
	if (count == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 다시 temp 그래프 초기화
				temp[i][j] = arr[i][j];
			}
		}

		// 바이러스(2)인 위치에서 전파 진행
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (temp[i][j] == 2)
					virus(i, j);
			}
		}

		// 안전 영역의 최대값 계산
		res = max(res, getScore());
		return;
	}

	// 울타리 설치
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				count += 1;
				dfs(count);
				arr[i][j] = 0;
				count--;
			}
		}
	}
}

int main(void)
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	dfs(0);
	cout << res;
}