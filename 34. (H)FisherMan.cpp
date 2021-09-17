/*

https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman/problem

There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)

Distance between consecutive spots = distance between gate and nearest spot = 1 m

Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

image

Input Format

Number of fishing spots, N Position of the gates, Gi, 1 < i < 3 Number of fishermen at each gates, G_n_i

Constraints

1 <= N <= 10 1 <= G_i <= N 1 <= G_n_i <= 15

Output Format

Output single integer

Sample Input 0

10
4 6 10
5 2 2
Sample Output 0

18

*/

#include <iostream>
using namespace std;

int n;
int ans = 1000000;
bool vis[16];

int near(int gate) {
	for (int i = gate, j = gate; i >= 1 || j <= n; i--, j++) {
		if (i >= 1 && !vis[i]) return i;
		if (j <= n && !vis[j]) return j;
	}

	return -1;
}

void helper(int a[], int b[], int dist) {
	if (b[0] == 0 && b[1] == 0 && b[2] == 0) {
		if (dist < ans) ans = dist;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (b[i] > 0) {
			int nearest = near(a[i]);
			b[i] -= 1;
			vis[nearest] = true;
			helper(a, b, dist + abs(a[i] - nearest) + 1);
			vis[nearest] = false;
			b[i] += 1;
		}
	}
}

int main() {
	cin >> n;
	int a[3], b[3];
	for (int i = 0; i <= n; ++i) {
		vis[i] = false;
	}
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> b[i];
	}
	helper(a, b, 0);
	cout << ans;
	return 0;
}