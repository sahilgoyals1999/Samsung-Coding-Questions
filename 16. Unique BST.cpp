/*

https://leetcode.com/problems/unique-binary-search-trees/

*/

int solve(int n, int dp[]) {
	if (n == 0) return 1;
	if (dp[n] != -1) {
		return dp[n];
	}
	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		int left = solve(i, dp);
		int right = solve(n - 1 - i, dp);
		ans += (left * right);
	}
	return dp[n] = ans;
}

int numTrees(int n) {
	int dp[n + 1];
	for (int i = 0; i <= n; ++i) {
		dp[i] = -1;
	}
	return solve(n, dp);
}