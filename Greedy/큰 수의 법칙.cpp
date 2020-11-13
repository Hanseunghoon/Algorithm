#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

int main(void) {

	int n, m, k, res = 0;

	cin >> n >> m >> k;
	int tmp = m;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	for (int i = 0; i < m; i++) {

		if (tmp < k) {
			res += arr[1] * tmp;
			cout << res;
			break;
		}

		res += arr[0] * k;
		tmp -= k;
	}
}