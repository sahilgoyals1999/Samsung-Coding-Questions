/*

There are N pots. Every pot has some water in it. They may be partially filled.
Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow.
The crow knows O1 to On(overflow no. for all the pots).
Crow wants some K pots to be overflow.
So the task is a minimum number of stones he can make K pots overflow in the worst case.

Array of overflow no --> {1,...,On}
Number of pots --> n
No of pots to overflow --> k

Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1).
So crow will put 5 stones in a pot with overflow no.(58), it will not overflow,
then he will put in the pot with overflow no.(5),
hence the total no. of stones to make overflow one-pot is=10.

*/

#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

void merger(int overflow_numbers[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = overflow_numbers[l + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = overflow_numbers[m + 1 + j];
	}
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			overflow_numbers[k++] = L[i++];
		}
		else {
			overflow_numbers[k++] = R[j++];
		}
	}
	while (i < n1) {
		overflow_numbers[k++] = L[i++];
	}
	while (j < n2) {
		overflow_numbers[k++] = R[j++];
	}
}


void merge_sort(int overflow[], int l, int r) {
	if (l >= r) return;
	int m = l + (r - l) / 2;
	merge_sort(overflow, l, m);
	merge_sort(overflow, m + 1, r);
	merger(overflow, l, m, r);
}

int minCrowPotStoneSecond(int overflow_numbers[]) {
	int total_stones = 0;

	for (int i = n - 1; i > 0; i--) {
		overflow_numbers[i] = overflow_numbers[i] - overflow_numbers[i - 1];
	}

	for (int i = 0; i < k; i++) {
		total_stones += (overflow_numbers[i] * (n - i));
	}
	return total_stones;
}

int main() {
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	merge_sort(arr, 0, n - 1);

	cout << minCrowPotStoneSecond(arr);
	return 0;
}