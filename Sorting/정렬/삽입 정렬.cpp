#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {

	int tmp;

	// 두번째 데이터부터 제자리를 찾아가는 방식의 반복문
	for (int i = 1; i < arr.size(); i++) {

		// i번째 데이터 앞의 수부터 앞으로 가면서 자리 찾기
		for (int j = i; j > 0; j--) {

			// 자리를 찾아가다 자기보다 큰 수를 만나면 정지
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else
				break;
		}

		// 단계별로 정렬되는 배열 출력
		for (int k = 0; k < arr.size(); k++)
			cout << arr[k] << " ";
		cout << endl;
	}

	return 0;
}