/*

https://www.geeksforgeeks.org/bipartite-graph/

Given a graph print either of the set of the vertices that are colored with the same color.
And if the graph is not bipartite print “-1”.
Test cases also included cases when a graph is not connected.

*/

#include <iostream>
using namespace std;

int nodes, edges;
int a[1000][10001], color[10001], x, y;

bool check(int src) {
	int q[10001];
	color[i] = 0;
	int start = 0, end = 0;
	q[end++] = src;
	while (start != end) {
		int x = q[start++];
		for (int i = 0; i < nodes; i++) {
			if (a[x][i] == 1 && color[i] == -1) {
				color[i] = 1 - color[x];
				q[end++] = i;
			}
			else if (a[x][i] == 1 && color[i] == color[x]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> nodes >> edges;
	for (int i = 0; i < nodes; i++) {
		color[i] = -1;
	}
	while (edges--) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 0; i < nodes; i++) {
		if (color[i] == -1) {
			if (!check(i)) {
				cout << "-1";
				return 0;
			}
		}
	}

	for (int i = 0; i < nodes; i++) {
		if (color[i] == 0) {
			cout << i << " ";
		}
	}
	return 0;
}
