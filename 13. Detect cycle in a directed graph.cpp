/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

*/

int a[1005][1005];

bool helper(int n, int sv, bool visited[], bool recStack[]) {
	visited[sv] = true;
	recStack[sv] = true;

	for (int i = 0; i < 1005; ++i) {
		if (a[sv][i] == 1 && !visited[i] && helper(n, i, visited, recStack)) return true;
		if (a[sv][i] == 1 && recStack[i]) return true;
	}

	recStack[sv] = false;

	return false;
}

bool isCyclic(int n) {
	bool visited[n] = {false};
	bool recStack[n] = {false};
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (helper(n, i, visited, recStack)) return true;
		}
	}

	return false;
}
