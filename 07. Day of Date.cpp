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

	int days = 0;

	if (y % 4 == 0) {
		if (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0)) {
			if (m == 2 && d == 29) {
				days++;
			}
			else if (m >= 3) {
				days++;
			}
		}
	}

	y--;
	days += y * 365;
	days += (y / 4 - y / 100 + y / 400);

	m--;
	if (m >= 1) days += dm[m - 1];
	days += d;
	return days % 7;
}

int main() {
	int d, m, y;
	cin >> d >> m >> y;
	char dd[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int day = dayofweek(d, m, y);
	cout << dd[day];
	return 0;
}