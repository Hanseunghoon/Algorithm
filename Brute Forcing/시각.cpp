#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, sum = 0;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (i % 3 == 0 && i != 0)
			sum += 3600;
		else
			sum += 105 * 15;
	}

	cout << sum;
}