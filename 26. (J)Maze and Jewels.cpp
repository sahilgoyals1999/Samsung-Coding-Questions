/*

There is a maze that has one entrance and one exit.
Jewels are placed in passages of the maze.
You want to pick up the jewels after getting into the maze through the entrance and before getting out of it through the exit.
You want to get as many jewels as possible, but you don’t want to take the same passage you used once.

When locations of a maze and jewels are given,
find out the greatest number of jewels you can get without taking the same passage twice,
and the path taken in this case.

Input:
The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line,
the size of the maze N (1 ≤ N ≤ 10) is given.
The maze is N×N square-shaped. From the second line through N lines,
information of the maze is given. '0' means a passage, '1' means a wall, and '2' means a location of a jewel.
The entrance is located on the upper-most left passage and the exit is located on the lower-most right passage.
There is no case where the path from the entrance to the exit doesn’t exist.

Output:
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

Output:
3 0 3 3 3
3 1 3 1 3
3 0 3 2 3
3 1 3 1 3
3 3 3 0 3
6
3 1 2 1 0 0
3 1 3 3 3 1
3 1 3 1 3 1
3 2 3 1 3 2
3 1 3 1 3 1
3 3 3 1 3 3
4

*/

#include <iostream>
using namespace std;

int n, a[101][101], ans[101][101];
bool vis[101][101];
int dx[4] = {0, 0, -1, +1};
int dy[4] = { -1, +1, 0, 0};

bool isValid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == false);
}

void solve(int cost, int cur_x, int cur_y, int des_x, int des_y, int &mx) {
	if (cur_x == des_x && cur_y == des_y) {
		if (cost > mx) {
			mx = cost;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (vis[i][j]) {
						ans[i][j] = 3;
					}
					else {
						ans[i][j] = a[i][j];
					}
				}
			}
		}
		return;
	}

	for (int ind = 0; ind < 4; ind++) {
		int nx = cur_x + dx[ind];
		int ny = cur_y + dy[ind];
		if (isValid(nx, ny)) {
			vis[nx][ny] = true;
			if (a[nx][ny] == 0) {
				solve(cost, nx, ny, des_x, des_y, mx);
			}
			else if (a[nx][ny] == 2) {
				solve(cost + 1, nx, ny, des_x, des_y, mx);
			}
			vis[nx][ny] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int mx = -10000000;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				vis[i][j] = false;
				ans[i][j] = a[i][j];
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
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
		cout << mx << endl;
	}
	return 0;
}