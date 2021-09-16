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

int findMinRec(int arr[], int i, int cur_sum, int sumTotal) {
	if (i < 0) {
		return abs((sumTotal - cur_sum) - cur_sum);
	}
	if (dp[i][cur_sum] != -1) {
		return dp[i][cur_sum];
	}

	int incl = findMinRec(arr, i - 1, cur_sum + arr[i], sumTotal);
	int excl = findMinRec(arr, i - 1, cur_sum, sumTotal);
	return dp[i][cur_sum] = min(incl, excl);
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

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= sumTotal; ++j) {
				dp[i][j] = -1;
			}
		}

		int diff = findMinRec(arr, n - 1, 0, sumTotal);

		int ans1 = (sumTotal - diff) / 2;
		int ans2 = (sumTotal - ans1);

		cout << ans1 << " " << ans2 << "\n";
	}
}