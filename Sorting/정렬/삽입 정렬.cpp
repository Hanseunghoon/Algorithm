#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {

	int tmp;

	// �ι�° �����ͺ��� ���ڸ��� ã�ư��� ����� �ݺ���
	for (int i = 1; i < arr.size(); i++) {

		// i��° ������ ���� ������ ������ ���鼭 �ڸ� ã��
		for (int j = i; j > 0; j--) {

			// �ڸ��� ã�ư��� �ڱ⺸�� ū ���� ������ ����
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else
				break;
		}

		// �ܰ躰�� ���ĵǴ� �迭 ���
		for (int k = 0; k < arr.size(); k++)
			cout << arr[k] << " ";
		cout << endl;
	}

	return 0;
}