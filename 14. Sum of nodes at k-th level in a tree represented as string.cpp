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
				int val = 0;
				while (a[i] >= '0' && a[i] <= '9') {
					val = val * 10 + (a[i] - '0');
					i++;
				}
				i--;
				sum += val;
			}
		}
	}

	return sum;
}

int main() {
	int k, n = 0;
	cin >> k;
	char x;
	char a[10000];
	while (cin >> x) {
		a[n++] = x;
	}
	cout << sumAtKthLevel(a, n, k);
	return 0;
}
