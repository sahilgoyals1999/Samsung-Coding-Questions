/*

https://stackoverflow.com/questions/32645046/urinal-algorithm-a-simple-optimization

*/

#include<iostream>
using namespace std;

int n;
char a[1005];

int findNext() {
	int index = 0, maxGap = 0, position = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == 'X') {
			if (maxGap <= i - index) {
				maxGap = i - index;
				position = i - (maxGap + 1) / 2;
			}

			index = i;
		}
	}

	// 0 1 2 3 4 5 6 7 8 9 10 11
	// X 0 0 0 0 0 0 0 X 0 0  X

	return position;
}

int main() {
	cin >> n;
	a[0] = 'X';
	a[n + 1] = 'X';
	for (int i = 1; i <= n; i++) {
		a[i] = '_';
	}

	for (int i = 1; i <= n; i++) {
		int x = findNext();
		a[x] = 'X';

		for (int j = 1; j <= n; j++) {
			cout << a[j];
		}
		cout << "\n";
	}
}
