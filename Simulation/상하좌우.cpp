#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, x = 1, y = 1;
	string plans;

	cin >> n;
	cin.ignore();	// 버퍼 비우기

	// 연속해서 데이터를 받아 문자열로 저장하는 함수
	// 파이썬에 plans = input().split()과 같은 기능!
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++)
	{
		if (plans[i] == 'L' && y > 1)
			y--;
		else if (plans[i] == 'R' && y <= n - 1)
			y++;
		else if (plans[i] == 'U' && x > 1)
			x--;
		else if (plans[i] == 'D'&& x <= n - 1)
			x++;
	}

	cout << x << " " << y;
}