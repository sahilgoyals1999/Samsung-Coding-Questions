/*

https://gist.github.com/hunarjain/81ef3e32e57ef3299e37e211e0d29292

There is a mobile piece and a stationary piece on the N×M chessboard.
The available moves of the mobile piece are the same as set out in the image below.
You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.
Write a program to find out the minimum number moves to catch a piece.
Time limit:1 second (java: 2 seconds)
Input
Several test cases can be included in the inputs.
T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ≤ 20) are given in a row.
N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of each test case.
R & C is the location information of the attacking piece and S & K is the location of the defending pieces and are given in the row at the second line.
However, the location of the uppermost end of the left end is (1, 1)
Output
For each test case, you should print "Case #T" in the first line where T means the case number.
For each test case, you should output the minimum number of movements to catch a defending piece at the first line of each test case.
If not moveable, output equals ‘-1’

Input:
1
7 13
2 8 3 4

Output:
Case #1 3

*/

#include <iostream>
using namespace std;

class qpair {
public:
	int x, y;

	qpair() {

	}

	qpair(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int n, m;

qpair q[1000001];
int start = 0, en = 0;
int vis[1001][1001];

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1};

int solve(int src_x, int src_y, int dest_x, int dest_y) {
	if (src_x == dest_x && src_y == dest_y) return 0;

	int ans = 0;
	qpair curr(src_x, src_y);
	q[en++] = curr;
	vis[src_x][src_y] = 1;
	while (start != en) {
		int currSize = en - start;
		while (currSize--) {
			curr.x = q[start].x;
			curr.y = q[start].y;
			start++;

			if (curr.x == dest_x && curr.y == dest_y) return ans;

			for (int ind = 0; ind < 8; ind++) {
				int i = curr.x + dx[ind];
				int j = curr.y + dy[ind];
				if (i <= n && j <= m && i > 0 && j > 0 && !vis[i][j]) {
					vis[i][j] = 1;
					qpair temp(i, j);
					q[en++] = temp;
				}
			}
		}
		ans++;
	}

	return -1;
}

int main() {
	int t;
	cin >> t;
	for (int k = 1; k <= t; ++k) {
		start = 0, en = 0;
		for (int i = 0; i < 1001; ++i) {
			for (int j = 0; j < 1001; ++j) {
				vis[i][j] = 0;
			}
		}
		cin >> n >> m;
		int src_x, src_y, dest_x, dest_y;
		cin >> src_x >> src_y >> dest_x >> dest_y;
		cout << "Case #" << k << " " << solve(src_x, src_y, dest_x, dest_y) << "\n";
	}
}