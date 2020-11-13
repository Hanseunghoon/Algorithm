#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N = 1260, res = 0;
	vector<int> coin = { 500, 100, 50, 10 };

	for (int i = 0; i < 4; i++) {
		res += N / coin[i];
		N %= coin[i];
	}

	cout << "µ¿Àü °¹¼ö : " << res << "°³";
}