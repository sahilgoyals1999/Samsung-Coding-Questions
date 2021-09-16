/*

Given a graph question. We have to find the loop in the graph if it exists and print the nodes of the loop in sorted order.

*/

#include <iostream>
using namespace std;

int a[100][100], n;

bool findcycle(int st, bool visited[], int parent, int &prev) {
	visited[st] = true;

	for (int j = 0; j < n; j++) {

		if (a[st][j] == 1 && visited[j] == false) {

			if ( findcycle(j, visited, st, prev) ) {
				if (st == prev) {
					cout << st << " ";
					prev = -1;
				}
				else if (prev != -1) {
					cout << st << " ";
				}

				return true;
			}

		}
		else if (a[st][j] == 1 && parent != j && visited[j] == true) {
			cout << st << " ";
			prev = j;
			return true;
		}

	}
	return false;
}

int main() {
	memset(a, 0, sizeof(a));
	int m;
	cin >> n >> m;

	int x, y;
	while (m--) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	bool visited[n] = {false};
	int parent = -1, prev = -1;
	findcycle(0, visited, parent, prev);

	return 0;
}

/*

Directed

*/

#include<iostream>
using namespace std;

int graph[100][100];
int n;

bool dfs( int node , bool *visited , bool *inloop , int &prev ) {
	visited[node] = 1;
	inloop[node] = 1;
	for (int i = 0; i < n; i++) {
		if ( graph[node][i]) {
			if (!visited[i]) {
				if (dfs( i , visited , inloop , prev)) {

					if (i == prev)
						cout << i << " " , prev = -1;
					else if (prev != -1)
						cout << i << " ";

					return true;
				}
			}
			else if ( inloop[i] ) {
				prev = i;
				return true;
			}
		}
	}

	inloop[node] = 0;
	return false;
}

bool checkCycle (bool *visited) {
	int prev = -1;
	bool inloop[n] = {false};

	for (int i = 0; i < n; i++)
		if ( !visited[i] && dfs(i, visited, inloop, prev))
			return true;

	return false;
}

int main() {
	// Input nodes
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;

	// Input Edges
	int t;
	cin >> t;
	int x, y;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
	}

	bool visited[n] = {false};

	cout << checkCycle(visited) << endl;

	return 0;
}