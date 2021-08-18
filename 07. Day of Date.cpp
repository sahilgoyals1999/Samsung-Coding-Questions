/*

https://practice.geeksforgeeks.org/problems/day-of-the-week1637/1

*/

#include <iostream>
using namespace std;

int dayofweek(int d, int m, int y) {
	int dm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1; i < 12; ++i) {
		dm[i] += dm[i - 1];
	}

	y--;
	m--;
	int days = y * 365;
	days += y / 4 - y / 100 + y / 400;
	if (m >= 1) days += dm[m - 1];
	days += d;

	return (days % 7);
}

int main() {
	char dd[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int day = dayofweek(18, 8, 2021);
	cout << dd[day];
	return 0;
}