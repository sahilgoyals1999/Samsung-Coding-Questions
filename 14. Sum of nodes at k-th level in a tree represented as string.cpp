/*

https://www.geeksforgeeks.org/sum-nodes-k-th-level-tree-represented-string/

*/

#include <iostream>
using namespace std;

int sumAtKthLevel(char a[], int n, int k) {
	int level = -1, sum = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') {
			level++;
		}
		else if (a[i] == ')') {
			level--;
		}
		else {
			if (level == k) {
				sum += (a[i] - '0');
			}
		}
	}

	return sum;
}

int main() {
	int n, k;
	cin >> n >> k;
	char a[n];
	cin >> a;
	cout << sumAtKthLevel(a, n, k);
	return 0;
}
