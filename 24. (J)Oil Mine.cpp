/*

There is an island surrounded by oil mines.
You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner.
Remember the companies can have oil mines adjacent to each other and not in between of each other.
After distributing them compute the difference of oil mines from the company getting highest and company getting lowest.
This number should be minimum.(then only the distribution can be termed as fair).

Input:
  2
  2 4
  6 13 10 2
  2 4
  6 10 13 2

Output:
  5
  1

*/

#include <iostream>
using namespace std;

int companies, mines;

int MIN(int x, int y) {
	return (x >= y) ? y : x;
}

int MAX(int x, int y) {
	return (x >= y) ? x : y;
}

void calculateOilMines(int i, int oilMines[], int visited[], int minV, int maxV, int sum, int nodes, int &ans) {
	// Base Case
	if (visited[i]) {
		if (nodes == companies - 1) {
			int newMin = MIN(sum, minV);
			int newMax = MAX(sum, maxV);
			ans = min(ans, newMax - newMin);
		}
		return;
	}

	// Main Case
	visited[i] = 1;
	int j = (i + 1) % mines;

	calculateOilMines(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ans);

	int newMin = MIN(sum, minV);
	int newMax = MAX(sum, maxV);

	calculateOilMines(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ans);

	visited[i] = 0;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> companies >> mines;
		int oilMines[mines];
		int visited[mines];

		for (int i = 0; i < mines; i++) {
			cin >> oilMines[i];
			visited[i] = 0;
		}

		int ans = 10000000;
		for (int i = 0; i < mines; i++) {
			calculateOilMines(i, oilMines, visited, 100000, -100000, 0, 0, ans);
		}
		cout << ans << endl;
	}
	return 0;
}


// #include <iostream>
// using namespace std;
// int ans = 1234, n, m;
// int comp[1001], oil[1001];

// void diff() {
// 	int mn = 1234, mx = -1234;
// 	for (int i = 0; i < n; i++) {
// 		mx = max(mx, comp[i]);
// 		mn = min(mn, comp[i]);
// 	}
// 	ans = min(ans, mx - mn);
// }

// void solve(int en, int curr, int cno) {
// 	if ((curr + 1) % m == en) {
// 		for (int i = cno; i < n; i++) {
// 			comp[i] += oil[curr];
// 			diff();
// 			comp[i] -= oil[curr];
// 		}
// 		return;
// 	}
// 	if (cno == n) return;

// 	comp[cno] += oil[curr];
// 	solve(en, (curr + 1) % m, cno);
// 	solve(en, (curr + 1) % m, cno + 1);
// 	comp[cno] -= oil[curr];
// 	solve(en, curr, cno + 1);
// }

// int main() {
// 	cin >> n >> m;
// 	for (int i = 0; i < m; i++) {
// 		cin >> oil[i];
// 	}
// 	for (int i = 0; i < n; i++) {
// 		comp[i] = 0;
// 	}
// 	if (n > m) {
// 		cout << "-1" << endl;
// 	}
// 	else {
// 		for (int i = 0; i < m; i++) {
// 			solve(i, i, 0);
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }