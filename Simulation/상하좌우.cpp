#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, x = 1, y = 1;
	string plans;

	cin >> n;
	cin.ignore();	// ���� ����

	// �����ؼ� �����͸� �޾� ���ڿ��� �����ϴ� �Լ�
	// ���̽㿡 plans = input().split()�� ���� ���!
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