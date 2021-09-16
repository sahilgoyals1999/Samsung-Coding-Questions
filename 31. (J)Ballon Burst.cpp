/*

https://gist.github.com/gunpreet34/c0ac4fea06671ff9017263a1ee03648c

There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by

1. The multiplication of point assigned to balloon on left and that of right side.
2. Point assigned to left if no right exists
3. Point assigned to right if no left exists.
4. The point assigned to itself if no other balloon exists.

You have to output the maximum no of points possible.

Input:
4
1 2 3 4

Output:
20

3
2
1
4

*/

#include <iostream>
using namespace std;

// To find next left balloon that is not burst
int findLeft(int a[], int n, int j, bool isBurst[]) {
	for (int i = j - 1; i >= 0; i--) {
		if (!isBurst[i]) {
			return i;
		}
	}
	return -1;
}

// To find next right balloon that is not burst
int findRight(int a[], int n, int j, bool isBurst[]) {
	for (int i = j + 1; i < n; i++) {
		if (!isBurst[i]) {
			return i;
		}
	}
	return -1;
}

// Calculate points to burst the current balloon
int calc(int a[], int n, int j, bool isBurst[]) {

	int left = findLeft(a, n, j, isBurst);
	int right = findRight(a, n, j, isBurst);

	if (left != -1 && right != -1) {
		return a[left] * a[right];
	}
	else if (left != -1) {
		return a[left];
	}
	else if (right != -1) {
		return a[right];
	}
	return a[j];
}

void maxPoints(int a[], int n, int curr_ans, int &ans, int count, bool isBurst[]) {
	// If number of balloons burst equals total number of balloons
	if (count == n) {
		if (curr_ans > ans) {
			ans = curr_ans;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!isBurst[i]) {
			isBurst[i] = true;
			maxPoints(a, n, curr_ans + calc(a, n, i, isBurst), ans, count + 1, isBurst);
			isBurst[i] = false;
		}
	}
}

int main() {
	int n, ans = 0;
	cin >> n;
	int a[n];
	bool isBurst[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		isBurst[i] = false;
	}
	maxPoints(a, n, 0, ans, 0, isBurst);
	cout << ans;
	return 0;
}