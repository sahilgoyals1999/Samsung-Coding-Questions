/*

https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing

*/

#include <iostream>
using namespace std;

int n, m, ans = 10000;
int a[101][101], dp[101][101];

bool isSafeH(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != 0);
}

bool isSafeV(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

void solve(int i, int j, int cost, int maxCost) {
	if (dp[i][j] > cost) {
		dp[i][j] = cost;
		if (a[i][j] == 3) {
			ans = min(ans, max(cost, maxCost));
			return;
		}
		if (isSafeH(i, j - 1) && a[i][j] == 1) {
			solve(i, j - 1, 0, max(cost, maxCost));
		}
		if (isSafeH(i, j + 1) && a[i][j] == 1) {
			solve(i, j + 1, 0, max(cost, maxCost));
		}
		if (isSafeV(i - 1, j)) {
			if (a[i][j]) {
				solve(i - 1, j, 1, max(cost, maxCost));
			}
			else {
				solve(i - 1, j, cost + 1, maxCost);
			}
		}
		if (isSafeV(i + 1, j)) {
			if (a[i][j]) {
				solve(i + 1, j, 1, max(cost, maxCost));
			}
			else {
				solve(i + 1, j, cost + 1, maxCost);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			dp[i][j] = 10000;
		}
	}
	solve(n - 1, 0, 0, 0);
	cout << ans;
	return 0;
}