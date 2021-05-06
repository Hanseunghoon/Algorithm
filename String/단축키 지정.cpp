#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, length;
vector<string> option(30);
vector<char> hotKey(30);
vector<int> hotKeyIdx(30, -1);

bool isExist(int i, int j) {
	for (int k = 0; k < i; k++) {
		if (tolower(option[i][j]) == hotKey[k]) {
			return true;
			break;
		}
	}
	return false;
}

int main() {

	cin >> n;
	getchar();

	for (int i = 0; i < n; i++) 
		getline(cin, option[i]);

	for (int i = 0; i < n; i++) {
		length = option[i].length();

		for (int j = 0; j < length; j++) {
			if (!isExist(i, j)) {
				hotKey[i] = tolower(option[i][j]);
				hotKeyIdx[i] = j;
				break;
			}
			else 
				while (option[i][++j] != ' ' && j < length);
		}

		if (hotKeyIdx[i] == -1) {

			for (int j = 0; j < length; j++) {
				if (option[i][j] == ' ') 
					continue;

				if (!isExist(i, j)) {
					hotKey[i] = tolower(option[i][j]);
					hotKeyIdx[i] = j;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {

		if (hotKeyIdx[i] == -1) 
			cout << option[i] << endl;
		else {
			int j;
			for (j = 0; j < hotKeyIdx[i]; j++)
				cout << option[i][j];
			
			cout << "[" << option[i][j] << "]";
			cout << &option[i][j + 1] << endl;
		}
	}
}