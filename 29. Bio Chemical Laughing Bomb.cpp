/*

https://gist.github.com/hunarjain/8dc698133576d7d71ff0607608837e06

You are busy to promote a newly released film in a movie theatre .
the title is 'Biochemical Laughing Bomb' which is about terror.
Guerillas drop a biochemical laughing bomb in the middle of a city.
once exposed, you have to laugh all your life.
The bomb will contaminate four people around it during t second, and another four around each of them during another one second.
However, you won't be contaminated if you are not in the adjacent four directions.
as the below shows the location of the bomb and affected people , and shows contamination process in seconds and you can figure out that the whole city is contaminated in 8 seconds.
In order to protect the city from the epidemic, create a program that figures out when the city will be contaminated by the bomb for the last.
Input
Several test cases can be included in the inputs.
T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ≤ 30) are given in a row.
The row and column of the city, N and M are given by being separated with a blank on the first row of each test case.
(1 ≤ N, M ≤ 100) The status within city is given by being separated with a blank from the second row to N number rows.
1 means people exist and 0 means people do not exist.
The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.
Output
For each test case, you should print "Case #T" in the first line where T means the case number.
For each test case, you should output how long does it take to contaminate al people on the first row of each test case.

Input:
1
4 4
1 0 0 1
1 0 0 1
0 1 1 1
0 0 1 1
1 1

Output:
Case #1 5

*/

#include <iostream>
using namespace std;

class qpair {
public:
    int x, y;

    qpair() {

    }

    qpair(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int n, m;
int a[101][101];
int bomb_x, bomb_y;
int dx[4] = { -1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

qpair q[10001];
int start = 0, en = 0;
int vis[101][101];

int solve() {
    a[bomb_x][bomb_y] = 2;
    qpair curr(bomb_x, bomb_y);
    q[en++] = curr;
    int ans = 0;
    while (start != en) {
        int currSize = en - start;
        while (currSize--) {
            curr.x = q[start].x;
            curr.y = q[start].y;
            start++;

            for (int ind = 0; ind < 4; ind++) {
                int i = curr.x + dx[ind];
                int j = curr.y + dy[ind];
                if (i < n && j < m && i >= 0 && j >= 0 && a[i][j] == 1) {
                    a[i][j] = 2;
                    qpair temp(i, j);
                    q[en++] = temp;
                }
            }
        }
        if (start != en) ans++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        cin >> bomb_x >> bomb_y;
        cout << "Case #" << k << " " << solve() << "\n";
    }
    return 0;
}
