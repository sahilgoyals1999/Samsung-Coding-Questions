/*

Jitesh ji

*/

#include <iostream>
using namespace std;
int n, a[10001];
int ans = 0;

void solve(int i, int s1, int s2) {
	if (i != 0 && s1 == s2) {
		ans = max(ans, s1);
	}
	if (i < n) {
		solve(i + 1, s1, s2);
		s1 += a[i];
		solve(i + 1, s1, s2);
		s1 -= a[i];
		s2 += a[i];
		solve(i + 1, s1, s2);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve(0, 0, 0);
	cout << ans << "\n";
	return 0;
}