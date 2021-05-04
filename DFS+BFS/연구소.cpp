#include <iostream>
#include <Algorithm>

using namespace std;

int n, m;
int arr[8][8]; // �ʱ� �� �迭
int temp[8][8]; // ���� ��ġ�� ���� �� �迭

// 4���� �̵� ���⿡ ���� �迭
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int result;

// ���� �켱 Ž��(DFS)�� �̿��� �� ���̷����� ������� �������� �ϱ�
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ��, ��, ��, �� �߿��� ���̷����� ���� �� �ִ� ���
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				// �ش� ��ġ�� ���̷��� ��ġ�ϰ�, �ٽ� ��������� ����
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

// ���� �ʿ��� ���� ������ ũ�� ����ϴ� �޼���
int getScore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score += 1;
			}
		}
	}
	return score;
}

// ���� �켱 Ž��(DFS)�� �̿��� ��Ÿ���� ��ġ�ϸ鼭, �� �� ���� ������ ũ�� ���
void dfs(int count) {
	// ��Ÿ���� 3�� ��ġ�� ���
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		// �� ���̷����� ��ġ���� ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}
		// ���� ������ �ִ밪 ���
		result = max(result, getScore());
		return;
	}
	// �� ������ ��Ÿ���� ��ġ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				count += 1;
				dfs(count);
				arr[i][j] = 0;
				count -= 1;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);
	cout << result << '\n';
}