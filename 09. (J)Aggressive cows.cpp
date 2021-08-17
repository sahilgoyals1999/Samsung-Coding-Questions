/*

https://www.spoj.com/problems/AGGRCOW/

*/

#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left + 1, n2 = right - mid;
	int tmp1[n1], tmp2[n2];
	int k = 0;
	// split it into 2 arrays A & B
	for (int i = left; i <= mid; ++i) {
		tmp1[k++] = A[i];
	}
	k = 0;
	for (int i = mid + 1; i <= right; ++i) {
		tmp2[k++] = A[i];
	}
	// Merge them
	int i = 0, j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (tmp1[i] < tmp2[j]) {
			A[k++] = tmp1[i++];
		}
		else {
			A[k++] = tmp2[j++];
		}
	}
	while (i < n1) {
		A[k++] = tmp1[i++];
	}
	while (j < n2) {
		A[k++] = tmp2[j++];
	}
}

void mergeSort(int A[], int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	// Sort left and right part
	mergeSort(A, left, mid);
	mergeSort(A, mid + 1, right);
	// merge them
	merge(A, left, mid, right);
}

bool isFeasible(int a[], int n, int cows, int distance) {
	int curr = a[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - curr >= distance) {
			// place next element if its distance from the previously placed element is greater than current mid
			curr = a[i];
			cnt++;
			if (cnt == cows) return true;
		}
	}

	return false;
}

int largestMinDistance(int a[], int n, int c) {
	mergeSort(a, 0, n - 1);

	int ans = -1;
	// consider the maximum possible distance => a[n-1] - a[0]
	// l is initialized with 1 because minimum distance between each element can be one and not a[0]
	int l = 1, r = a[n - 1] - a[0];
	while (l < r) {
		int mid = l + (r - l) / 2;

		// if it is possible to place k elements with minimum distance mid, search for higher distance
		if (isFeasible(a, n, c, mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}

	return ans;
}

int main() {
	int n, cows;
	cin >> n >> cows;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << largestMinDistance(a, n, cows);
}
