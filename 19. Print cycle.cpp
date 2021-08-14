/*

Given a graph question. We have to find the loop in the graph if it exists and print the nodes of the loop in sorted order.

*/

#include <iostream>
using namespace std;

int g[1001][1001];
int visited[1001];
int n, currColour;

void printCycle() {
	for (int i = 0; i < n; i++) {
		if (visited[i] == currColour) cout << i << " ";
	}
	cout << "\n";
}

bool helper(int sv, int prev) {
	visited[sv] = currColour;

	for (int i = 0; i < n; i++) {
		if (g[sv][i] && visited[i] >= currColour) {
			if (visited[i] == currColour) {
				if (i != prev) return true;
				else continue;
			}

			if (helper(i, sv)) return true;
		}
	}

	return false;
}

void cycle() {
	currColour = 0;
	for (int i = 0; i < n; i++) {
		visited[i] = 1000000;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1000000) {
			if (helper(i, -1)) {
				printCycle();
			}
			currColour++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}

	cycle();
}