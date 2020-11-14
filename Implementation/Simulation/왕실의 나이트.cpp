#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	string input;
	cin >> input;

	int x = input[0] - 96, y = input[1] - 48, res = 8;

	if (x + 1 > 8 || y + 2 > 8)
		res--;
	if (x - 1 < 1 || y + 2 > 8)
		res--;
	if (x - 1 < 1 || y - 2 < 1)
		res--;
	if (x + 1 > 8 || y - 2 < 1)
		res--;
	if (x + 2 > 8 || y + 1 > 8)
		res--;
	if (x + 2 > 8 || y - 1 < 1)
		res--;
	if (x - 2 < 1 || y - 1 < 1)
		res--;
	if (x - 2 < 1 || y + 1 > 8)
		res--;

	cout << res;
}