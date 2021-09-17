/*

https://www.youtube.com/watch?v=9TihPDzWufc&list=PLVjKfYZRuZ-KXsO2dprGDi-g9lF0m3yhm&index=5

https://discuss.codechef.com/t/help-needed-for-a-bfs-problem/36778

You are given an old touch smartphone numbers having dial pad and calculator app.
The goal is to type a number on dial-pad.
Calculator have 0-9 and +, -, * , /, = as operations.
But as the phone is old, some of the numbers and some operations can't be touched.
But you can always make a number using other numbers and operations.
There could be multiple ways of making a number.
You have to find minimum operation for making a number.
For ex: lets say 1,4,6,7,8,9 works and +,-,* works. 2,3,5 and / doesn't work.
If you have to type 18 -> 2 operations. (Each touch is considered an operation).
If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
The goal is to find minimum operations.

Input:
There will be multiple Test cases .Each test case will consist of 4 lines
1) First line will consist of N,M,O
N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
M: types of operations allowed (1--> '+', 2--> '-', 3--> '*' , 4--> '/' )
O: Max no of touches allowed

2) second line of input contains the digits that are working e.g 0,2,3,4,6.
3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
4) fourth line contains the number that we want to make .

Output:
Output contains 1 line printing the number of touches required to make the number

Sample Test Case:

4
5 3 5
1 2 4 6 0
1 2 3
5
6 4 5
1 2 4 6 9 8
1 2 3 4
91
6 3 4
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981

Output:
4 // 1+4= , "=" is also counted as a touch
2 // 91 can be made by directly entering 91 as 1,9 digits are working, so only 2 operations
5 // 35-7=, other ways are 1+3*9=
9 // 62*16-11=

*/

#include<iostream>
using namespace std;

int n, m, o, target;
int digits[10], opr[4];
int ans;

int calc(int a, int b, int operation) {
    if (operation == 1) return a + b;
    else if (operation == 2) return a - b;
    else if (operation == 3) return a * b;
    else if (operation == 4) return a / b;
    else return (a * 10) + b;
}

void helper(int prev, int curr, int operation, int touches) {
    if (operation == -1) {
        if (prev == target && touches <= o && touches < ans) {
            ans = touches;
        }
    }
    else if (calc(prev, curr, operation) == target) {
        if (touches < o && touches + 1 < ans) {
            ans = touches + 1;
        }
    }

    if (touches >= o) return;

    for (int i = 0; i < n; i++) {
        if (operation == -1) helper(calc(prev, digits[i], -1), -1, -1, touches + 1);
        else if (touches >= o - 1) continue;
        else helper(prev, calc(curr, digits[i], -1), operation, touches + 1);

        for (int j = 0; j < m; j++) {
            if (digits[i] == 0 && opr[j] == 4) continue;
            else if (digits[i] == 0 && curr == -1) break;

            if (curr == -1) helper(prev, digits[i], opr[j], touches + 2);
            else helper(calc(prev, curr, operation), digits[i], opr[j], touches + 2);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> o;
        for (int i = 0; i < n; i++) {
            cin >> digits[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> opr[i];
        }
        cin >> target;

        ans = 1000000000;

        for (int i = 0; i < n; i++) {
            if (digits[i] == target) {
                ans = 1;
                break;
            }
            else if (digits[i] != 0) {
                helper(digits[i], -1, -1, 1);
            }
        }

        cout << ans << "\n";
    }
}