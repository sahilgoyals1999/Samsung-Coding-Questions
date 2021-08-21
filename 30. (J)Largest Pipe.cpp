/*

https://gist.github.com/hunarjain/931c3d01f7594b5b1bb19e71dccf347b

Given number of pipes 1..n,
Find two largest pipes of maximum length possible.
Input: 1,2,3,4,6
Output: The maximum length possible is 8. Pipe1 - 2,6 Pipe2 - 1,3,4

*/

#include <iostream>
using namespace std;

int dp[1001][1001];

int findMinRec(int arr[], int i, int sumCalculated, int sumTotal) {
	if (i == 0) {
		return abs((sumTotal - sumCalculated) - sumCalculated);
	}

	int incl = findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal);
	int excl = findMinRec(arr, i - 1, sumCalculated, sumTotal);
	return dp[i][sumCalculated] = min(incl, excl);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int arr[n];
		int sumTotal = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sumTotal += arr[i];
		}

		int diff = findMinRec(arr, n, 0, sumTotal);

		int ans1 = (sumTotal - diff) / 2;
		int ans2 = (sumTotal - ans1);

		cout << ans1 << " " << ans2 << "\n";
	}

	// int dp[1005][1005];
	// int dp1[1005][1005];

	// for (int i = 0; i <= 1000; i++) {
	// 	for (int j = 0; j <= 1000; j++) {
	// 		dp[i][j] = 0;
	// 	}
	// }

	// dp[0][0] = 1;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= 1000; j++) {
	// 		for (int k = 0; k <= 1000; k++) {
	// 			if (j >= arr[i]) {
	// 				if (dp[j - arr[i]][k]) {
	// 					dp1[j][k] = 1;
	// 				}
	// 			}
	// 			if (k >= arr[i]) {
	// 				if (dp[j][k - arr[i]]) {
	// 					dp1[j][k] = 1;
	// 				}
	// 			}
	// 			if (dp[j][k]) {
	// 				dp1[j][k] = 1;
	// 			}
	// 		}
	// 	}

	// 	for (int j = 0; j <= 1000; j++) {
	// 		for (int k = 0; k <= 1000; k++) {
	// 			dp[j][k] = dp1[j][k];
	// 			dp1[j][k] = 0;
	// 		}
	// 	}
	// }

	// int ans = 0;
	// for (int i = 1; i <= 1000; i++) {
	// 	if (dp[i][i]) {
	// 		ans = i;
	// 	}
	// }
	// cout << ans << endl;

	return 0;
}