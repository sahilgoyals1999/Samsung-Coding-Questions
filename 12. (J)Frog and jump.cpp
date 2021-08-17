/*

Given a 2 D matrix where 1 represents the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in the horizontal direction (on 1’s only) without incurring any cost (jump).
A vertical jump from a given point of the matrix to another point on the matrix can be taken (on 1’s only) with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump)

*/

#include <iostream>
using namespace std;

int a[101][101], dp[101][101];
int n, m, sx, sy, dx, dy;

bool isSafe(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

void solve(int i, int j, int cost) {
	if (dp[i][j] > cost) {
		dp[i][j] = cost;
		if (isSafe(i + 1, j) && a[i + 1][j] == 1) {
			solve(i + 1, j, cost + 1);
		}
		if (isSafe(i - 1, j) && a[i - 1][j] == 1) {
			solve(i - 1, j, cost + 1);
		}
		if (isSafe(i, j - 1) && a[i][j - 1] == 1) {
			solve(i - 1, j, cost);
		}
		if (isSafe(i, j + 1) && a[i][j + 1] == 1) {
			solve(i, j + 1, cost);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			dp[i][j] = 100000;
		}
	}
	cin >> sx >> sy >> dx >> dy;
	solve(sx, sy, 0);
	cout << dp[dx - 1][dy - 1];
}