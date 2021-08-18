/*

https://practice.geeksforgeeks.org/problems/convex-hull2138/1

https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/

Input:
7
0 3
2 2
1 1
2 1
3 0
0 0
3 3

Output:
(0, 3)
(0, 0)
(3, 0)
(3, 3)

*/

#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

/*
To find orientation of ordered triplet (p, q, r).
The function returns following values
0 --> p, q and r are colinear
1 --> Clockwise
2 --> Counterclockwise
*/

int orientation(Point p, Point q, Point r) {
	// slope of pq - slope of qr
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void convexHull(Point points[], int n) {
	Point ans[101];
	int sz = 0;
	// There must be at least 3 points
	if (n < 3) {
		cout << "-1\n";
		return;
	}
	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (points[i].x < points[l].x) {
			l = i;
		}
	}
	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again. This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q;
	do {
		// Add current point to result
		ans[sz++] = points[p];

		// Search for a point 'q' such that orientation(p, q,
		// x) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (p + 1) % n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			// If i is more counterclockwise than current q, then update q
			if (orientation(points[p], points[i], points[q]) == 2) {
				q = i;
			}
			else if (orientation(points[p], points[i], points[q]) == 0) {
				cnt++;
			}
		}
		if (cnt == n) break;
		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l); // While we don't come to first point

	int i = 0, j = 1;
	while (j < sz) {
		if (ans[i].x != ans[j].x || ans[i].y != ans[j].y) {
			i++;
			swap(ans[i], ans[j]);
			j++;
		}
		else {
			j++;
		}
	}
	if (i < 2) {
		cout << "-1\n";
		return;
	}
	for (int k = 0; k <= i; ++k) {
		cout << "(" << ans[k].x << ", " << ans[k].y << ")\n";
	}
}

int main() {
	int n;
	cin >> n;
	Point points[n];
	for (int i = 0; i < n; ++i) {
		cin >> points[i].x >> points[i].y;
	}
	convexHull(points, n);
	return 0;
}
