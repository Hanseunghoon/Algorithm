#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {

	for (int i = 0; i < arr.size(); i++) {

		// 맨 앞 숫자를 임시 저장할 변수
		int tmp = arr[i];
		// 정렬되지 않은 수 중 가장 최소값의 인덱스를 저장할 변수
		int min_idx = i;

		// 최소값의 인덱스를 구하는 반복문
		for (int j = i + 1; j < arr.size(); j++)
			min_idx = arr[min_idx] > arr[j] ? j : min_idx;

		// 스와핑
		arr[i] = arr[min_idx];
		arr[min_idx] = tmp;

		// 단계별로 정렬되는 배열 출력
		for (int k = 0; k < arr.size(); k++)
			cout << arr[k] << " ";
		cout << endl;
	}

	return 0;
}