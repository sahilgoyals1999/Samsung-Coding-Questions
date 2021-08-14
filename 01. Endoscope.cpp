/*

https://www.hackerearth.com/problem/algorithm/question-7-4/

*/

#include <iostream>
using namespace std;

class qpair {
public:
	int x, y;
};

qpair q[1000005];
int row, col, l;

int a[1005][1005], vis[1005][1005];

bool up(int x1, int y, int x2) {
	if (x2 < 0 || a[x2][y] == 0 || vis[x1][y] == l || vis[x2][y] != 0) return false;

	if ((a[x1][y] == 1 || a[x1][y] == 2 || a[x1][y] == 4 || a[x1][y] == 7) &&
	        (a[x2][y] == 1 || a[x2][y] == 2 || a[x2][y] == 5 || a[x2][y] == 6)) return true;
	return false;
}

bool down(int x1, int y, int x2) {
	if (x2 >= row || a[x2][y] == 0 || vis[x1][y] == l || vis[x2][y] != 0) return false;

	if ((a[x1][y] == 1 || a[x1][y] == 2 || a[x1][y] == 5 || a[x1][y] == 6) &&
	        (a[x2][y] == 1 || a[x2][y] == 2 || a[x2][y] == 4 || a[x2][y] == 7)) return true;
	return false;
}

bool left(int x, int y1, int y2) {
	if (y2 < 0 || a[x][y2] == 0 || vis[x][y1] == l || vis[x][y2] != 0) return false;
	if ((a[x][y1] == 1 || a[x][y1] == 3 || a[x][y1] == 6 || a[x][y1] == 7) &&
	        (a[x][y2] == 1 || a[x][y2] == 3 || a[x][y2] == 4 || a[x][y2] == 5)) return true;
	return false;
}

bool right(int x, int y1, int y2) {
	if (y2 >= col || a[x][y2] == 0 || vis[x][y1] == l || vis[x][y2] != 0) return false;
	if ((a[x][y1] == 1 || a[x][y1] == 3 || a[x][y1] == 4 || a[x][y1] == 5) &&
	        (a[x][y2] == 1 || a[x][y2] == 3 || a[x][y2] == 6 || a[x][y2] == 7)) return true;

	return false;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> row >> col >> x >> y >> l;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> a[i][j];
				vis[i][j] = 0;
			}
		}
		if (a[x][y] == 0) {
			cout << "0" << endl;
		}
		else if (l == 1) {
			cout << "1" << endl;
		}
		else {
			qpair p;
			int start = 0, end = 0, ans = 0;
			p.x = x;
			p.y = y;
			q[end++] = p;
			vis[x][y] = 1;
			while (start != end) {
				p = q[start];
				int i = p.x;
				int j = p.y;
				start++;
				if (up(i, j, i - 1)) {
					p.x = i - 1;
					p.y = j;
					q[end++] = p;
					vis[i - 1][j] = 1 + vis[i][j];
				}
				if (down(i, j, i + 1)) {
					p.x = i + 1;
					p.y = j;
					q[end++] = p;
					vis[i + 1][j] = 1 + vis[i][j];
				}
				if (left(i, j, j - 1)) {
					p.x = i;
					p.y = j - 1;
					q[end++] = p;
					vis[i][j - 1] = 1 + vis[i][j];
				}
				if (right(i, j, j + 1)) {
					p.x = i;
					p.y = j + 1;
					q[end++] = p;
					vis[i][j + 1] = 1 + vis[i][j];
				}
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (vis[i][j] != 0) {
						ans++;
					}
				}
			}

			cout << ans << endl;
		}
	}
	return 0;
}