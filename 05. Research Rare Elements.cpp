/*

https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092

A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce overall cost of research over there.
It is given that all the rare-element’s location is connected by roads.
It is also given that Research Center can only be build on road.
Team decided to assign this task to a coder.If you feel you have that much potential…

Here is the Task :-
Find the shortest of the longest distance of research center from given locations of rare-elements.
locations are given in the matrix cell form where 1 represents roads and 0 no road…
number of rare-element and their location was also given(number<=5)
and order of square matrix was less than equal to (20).

*/

#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

bool a[21][21];
bool vis[21][21];
int dist[21][21];
int n;

class Point {
public:
	int x, y;
};

class Tuple {
public:
	int x, y;
	int dis;
};

bool isSafe(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1 && !vis[x][y]);
}

void init() {
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			dist[i][j] = 10000;
			vis[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	Tuple q[10001];
	int start = 0, end = 0;
	Tuple cur;
	cur.x = x;
	cur.y = y;
	cur.dis = 0;
	q[end++] = cur;
	vis[x][y] = 1;

	while (start != end) {
		cur = q[start++];
		int a = cur.x;
		int b = cur.y;
		int d = cur.dis;
		dist[a][b] = d;

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (isSafe(nx, ny)) {
				vis[nx][ny] = 1;
				cur.x = nx;
				cur.y = ny;
				cur.dis = d + 1;
				q[end++] = cur;
			}
		}

	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int q;
	cin >> q;
	Point rare[q];

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		rare[i].x = a;
		rare[i].y = b;
	}

	int ans = 10000;

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			init();
			bool flag = false;
			int mx = -1;
			if (a[i][j] == 1) {
				bfs(i, j);
				for (int k = 0; k < q; k++) {
					if (dist[rare[k].x][rare[k].y] == 10000) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					for (int k = 0; k < q; k++) {
						mx = max(mx, dist[rare[k].x][rare[k].y]);
					}
				}
				ans = min(ans, mx);
			}
		}
	}

	cout << ans << "\n";
}