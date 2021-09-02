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

*/

#include <iostream>
using namespace std;

// To find next left balloon that is not burst
int findLeft(int a[], int n, int j, bool isBurst[], bool &found) {
	if (j <= 0) {
		found = false;
		return 1;
	}
	for (int i = j - 1; i >= 0; i--) {
		if (!isBurst[i]) {
			return a[i];
		}
	}
	found = false;
	return 1; // If no ballon found return 1
}

// To find next right balloon that is not burst
int findRight(int a[], int n, int j, bool isBurst[], bool &found) {
	if (j >= n) {
		found = false;
		return 1;
	}
	for (int i = j + 1; i < n; i++) {
		if (!isBurst[i]) {
			return a[i];
		}
	}
	found = false;
	return 1; // If no ballon found return 1
}

int calc(int a[], int n, int j, bool isBurst[]) { //Calculate points to burst the current balloon
	int points = 0;
	bool leftFound = true, rightFound = true; //To check if balloons exist to the left and right of current balloon
	int left = findLeft(a, n - 1, j, isBurst, leftFound);
	int right = findRight(a, n - 1, j, isBurst, rightFound);
	if (!leftFound && !rightFound) { //If current balloon is the last balloon
		points += a[j];
	}
	else {
		points += (left * right);
	}
	return points;
}

void maxPoints(int a[], int n, int cp, int curr_ans, int &ans, int count, bool isBurst[]) {
	if (count == n) { //If number of balloons burst equals total number of balloons
		if (curr_ans > ans) {
			ans = curr_ans;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!isBurst[i]) {
			isBurst[i] = true;
			maxPoints(a, n, i, curr_ans + calc(a, n, i, isBurst), ans, count + 1, isBurst);
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
	maxPoints(a, n, 0, 0, ans, 0, isBurst);
	cout << ans;
	return 0;
}