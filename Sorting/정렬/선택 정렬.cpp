#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {

	for (int i = 0; i < arr.size(); i++) {

		// �� �� ���ڸ� �ӽ� ������ ����
		int tmp = arr[i];
		// ���ĵ��� ���� �� �� ���� �ּҰ��� �ε����� ������ ����
		int min_idx = i;

		// �ּҰ��� �ε����� ���ϴ� �ݺ���
		for (int j = i + 1; j < arr.size(); j++)
			min_idx = arr[min_idx] > arr[j] ? j : min_idx;

		// ������
		arr[i] = arr[min_idx];
		arr[min_idx] = tmp;

		// �ܰ躰�� ���ĵǴ� �迭 ���
		for (int k = 0; k < arr.size(); k++)
			cout << arr[k] << " ";
		cout << endl;
	}

	return 0;
}