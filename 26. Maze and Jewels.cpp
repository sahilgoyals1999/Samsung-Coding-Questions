/*

There is a maze that has one entrance and one exit.
Jewels are placed in passages of the maze.
You want to pick up the jewels after getting into the maze through the entrance and before getting out of it through the exit.
You want to get as many jewels as possible, but you don’t want to take the same passage you used once.

When locations of a maze and jewels are given,
find out the greatest number of jewels you can get without taking the same passage twice,
and the path taken in this case.

Input
There can be more than one test case in the input file.
The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line,
the size of the maze N (1 ≤ N ≤ 10) is given.
The maze is N×N square-shaped. From the second line through N lines,
information of the maze is given. “0” means a passage, “1” means a wall, and “2” means a location of a jewel.
The entrance is located on the upper-most left passage and the exit is located on the lower-most right passage.
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines,
mark the path with 3 and output it. In N+1 line,
output the greatest number of jewels that can be picked up.
Each test case must be output separately as a empty.

Input:
2
5
0 0 0 2 0
2 1 0 1 2
0 0 2 2 0
0 1 0 1 2
2 0 0 0 0
6
0 1 2 1 0 0
0 1 0 0 0 1
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0

*/

#include <iostream>
using namespace std;

int n, a[101][101], dp[101][101];
bool vis[101][101];
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == false);
}

void solve(int cost, int currx, int curry, int desx, int desy, int &mx) {
	if (currx == desx && curry == desy) {
		if (cost > mx) {
			mx = cost;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (vis[i][j])
						dp[i][j] = 3;
					else dp[i][j] = a[i][j];
		}
		return;
	}
	for (int k = 0; k < 4; k++) {
		if (isValid(currx + x[k], curry + y[k])) {
			int tempx = currx + x[k];
			int tempy = curry + y[k];
			vis[tempx][tempy] = true;
			if (a[tempx][tempy] == 0) {
				solve(cost, tempx, tempy, desx, desy, mx);
			}
			else if (a[tempx][tempy] == 2) {
				solve(cost + 1, tempx, tempy, desx, desy, mx);
			}
			vis[tempx][tempy] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int mx = -123;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				vis[i][j] = false;
				dp[i][j] = a[i][j];
			}
		}
		vis[0][0] = true;
		if (a[0][0] == 0) {
			solve(0, 0, 0, n - 1, n - 1, mx);
		}
		else if (a[0][0] == 2) {
			solve(1, 0, 0, n - 1, n - 1, mx);
		}
		vis[0][0] = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << mx << endl;
	}
	return 0;
}