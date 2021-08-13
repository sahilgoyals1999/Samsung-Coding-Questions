/*

https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix-from-top-left-to-bottom-right/

*/

int a[1005][1005];
int n, m;

int MaximumPath() {
	int sums[n][m] = {};
	sums[0][0] = a[0][0];

	for (int i = 1; i < n; i++) {
		sums[i][0] = a[i][0] + sums[i - 1][0];
	}

	for (int j = 1; j < m; j++) {
		sums[0][j] = a[0][j] + sums[0][j - 1];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			sums[i][j] = a[i][j] + max(sums[i - 1][j], sums[i][j - 1]);
		}
	}

	return sum[n - 1][m - 1];
}
