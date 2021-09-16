/*

you are given T test cases
in each test case you are given N & K
K is maximum pressure Tyre can hold and 0 is minimum pressure.
N is number of operations (first inflate air in tyre , then deflate air from tyre) tyre will undergo.
                          take input in 2 arrays inflate[ N ] & deflate[ N ]
Now Let say Tyre has initial pressure X,
we have to find minimum initial pressure so that tyre can pass all N operations.
Also the order in which N operations execute can vary means we have to look for all possibilities until we get answer.

Approach : Backtracking
Take intitial pressure start from 0 to K and where we pass N operation will be answer

*/

#include <iostream>
using namespace std;

int n, k;
int inflate[8];
int deflate[8];
bool vis[8];

bool solveUtil(int p, int i, int count) {
	int inf = p + inflate[i];  // inflate air in tyre
	if (inf > k) {
		return false;
	}
	int df = inf - deflate[i];   // deflate air from tyre
	if (df < 0) {
		return false;
	}
	if (count == n) {
		return true;
	}
	bool ans = false;
	for (int j = 0; j < n; j++) {
		if (!vis[j]) {
			vis[j] = true;
			ans = solveUtil(df, j, count + 1);
			if (ans) {
				return true;
			}
			vis[j] = false;
		}
	}
	if (!ans) {
		return false;
	}

}

bool solve(int p)  { // p is pressure
	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			ans = solveUtil(p, i, 1);
			if (ans) {
				return true;
			}
			vis[i] = false;
		}
	}
	if (!ans) {
		return false;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> inflate[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> deflate[i];
		}
		bool ans = false;
		for (int i = 0; i <= k; i++) {
			bool ans = solve(i);
			if (ans) {
				cout << i << endl;
				break;
			}
		}
		if (!ans) {
			cout << "-1\n";
		}
	}
	return 0;
}