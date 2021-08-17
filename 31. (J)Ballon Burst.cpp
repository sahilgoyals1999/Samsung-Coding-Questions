/*

There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by

1. The multiplication of point assigned to balloon on left and that of right side.
2. Point assigned to left if no right exists
3. Point assigned to right if no left exists.
4. The point assigned to itself if no other balloon exists.

You have to output the maximum no of points possible.

Input:
1 2 3 4

Output:
20

*/

#include <bits/stdc++.h>
using namespace std;

int maxi(int x, int y) {
	if (x > y) return x;
	return y;
}

int main() {
	int n;
	cin >> n;
	int i, a[n + 9];
	a[0] = 1;
	a[n + 1] = 1;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int dp[n + 9][n + 9];
	for (i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			dp[i][j] = 0;
		}
	}

	// Calculate dp
	n = n + 2;
	for (int k = 2; k < n; k++) {
		for (int left = 0; left < n - k; left++) {
			int right = left + k;
			for (int i = left + 1; i < right; i++) {
				int temp;
				if (left == 0 && right == n - 1) {
					temp = (a[i] * a[left] * a[right] + dp[left][i] + dp[i][right]);
				}
				else {
					temp = (a[left] * a[right] + dp[left][i] + dp[i][right]);
				}
				dp[left][right] = maxi(dp[left][right], temp);
			}
		}
	}
	cout << dp[0][n - 1];
}