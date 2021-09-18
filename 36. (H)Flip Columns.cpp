/*

https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns

*/

#include <iostream>
using namespace std;

int n, m, k, a[51][51], ans;

void flip(int i) {
	for (int j = 0; j < n; ++j) {
		if (a[j][i] == 1) {
			a[j][i] = 0;
		}
		else {
			a[j][i] = 1;
		}
	}
}

void solve(int k) {
	if (k == 0) {
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = false;
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				tmp++;
			}
		}
		ans = max(ans, tmp);
		return;
	}

	for (int i = 0; i < m; ++i) {
		flip(i);
		solve(k - 1);
		flip(i);
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	solve(k);
	cout << ans;
}