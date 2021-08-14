/*

There is one spaceship.
X and Y co-ordinate of the source of spaceship and destination spaceship is given.
There is N number of wormholes; each wormhole has 5 values.
First 2 values are starting co-ordinate of the wormhole and after that value
no. 3 and 4 represent ending co-ordinate of the wormhole and
last 5th value is represents a cost to pass through this wormhole.
Now, these warmholes are bi-directional.
Now the cost to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find the minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you won't uses any warmhole.

1 1 100 100
3
2 25 7 89 6
19 78 5 75 11
2 27 19 67 10

135

*/

#include <iostream>
using namespace std;

int a[1001][5], ans, n;
bool vis[1001];

int abs(int x) {
	if (x < 0) return (-1 * x);
	return x;
}

int dist(int a, int b, int c, int d) {
	return abs(c - a) + abs(d - b);
}

void solve(int x, int y, int cost) {
	if (cost > ans) return;
	if (x == a[n + 1][0] && y == a[n + 1][1]) {
		if (cost < ans) {
			ans = cost;
		}
		return;
	}

	for (int i = 1; i <= n + 1; i++) {
		if (!vis[i]) {
			vis[i] = true;
			solve(a[i][2], a[i][3], cost + dist(x, y, a[i][0], a[i][1]) + a[i][4]);
			solve(a[i][0], a[i][1], cost + dist(x, y, a[i][2], a[i][3]) + a[i][4]);
			vis[i] = false;
		}
	}
}

int main() {
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	// src to src
	a[0][0] = sx;
	a[0][1] = sy;
	a[0][2] = sx;
	a[0][3] = sy;
	a[0][4] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
	// dest to dest
	a[n + 1][0] = dx;
	a[n + 1][1] = dy;
	a[n + 1][2] = dx;
	a[n + 1][3] = dy;
	a[n + 1][4] = 0;
	ans = abs(dx - sx) + abs(sy - dy);
	for (int i = 0; i <= n + 2; i++) {
		vis[i] = false;
	}
	solve(sx, sy, 0);
	cout << ans << "\n";
}