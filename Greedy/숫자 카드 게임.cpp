#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, max;
	cin >> n >> m;

	vector <vector<int>> matrix(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < n; i++)
		sort(matrix[i].begin(), matrix[i].end());

	max = matrix[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			max = matrix[i][0] > max ? matrix[i][0] : max;

	cout << max;
}