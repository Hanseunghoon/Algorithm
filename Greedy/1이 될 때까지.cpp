#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n = 30, k = 5, cnt = 0;
	//cin >> n >> k;

	while (n > 1) {
		if (n % k == 0)
			n /= k;
		else
			n -= 1;
		cnt++;
	}

	cout << cnt;
}