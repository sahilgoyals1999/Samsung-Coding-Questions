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

#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = { -1, +1, 0, 0};

bool ar[21][21];
bool vis[21][21];
int ans[21][21];
int n, q;

struct Point {
	int x, y;
};

struct C {
	int x, y;
	int dis;
};

Point P;
C c;

bool issafe(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1 && !vis[x][y]);
}

void bfs(int x, int y) {
	queue q;
	C in;
	in.x = x;
	in.y = y;
	in.dis = 0;
	q.push(in);
	vis[x][y] = 1;

	while (!q.empty()) {
		C c = q.front();
		q.pop();
		int a = c.x;
		int b = c.y;
		int d = c.dis;
		ans[a][b] = d;

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (issafe(nx, ny)) {
				vis[nx][ny] = 1;
				in.x = nx;
				in.y = ny;
				in.dis = d + 1;
				q.push(in);
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

	cin >> q;
	P rare[q];

	int fans = 10000;
	int mx = -1;

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;

		rare[i].x = a;
		rare[i].y = b;
	}


	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			memset(ans, 10000, sizeof(ans));
			int flag = 0;
			memset(vis, 0, sizeof(vis));
			mx = -1;
			if (a[i][j] == 1) {
				bfs(i, j);
				for (int k = 0; k < q; k++) {
					if (ans[rare[k].x][rare[k].y] == 10000) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					for (int k = 0; k < q; k++) {
						mx = max(mx, ans[rare[k].x][rare[k].y]);
					}
				}
				fans = min(fans, mx);
			}
		}
	}
	cout << fans << endl;
}