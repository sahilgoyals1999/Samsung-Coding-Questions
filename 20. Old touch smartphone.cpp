/*

You are given an old touch smartphone numbers having dial pad and calculator app.
The goal is to type a number on dial-pad.
Calculator have 1-9 and +, -, * , /, = as operations.
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
4 // no. of test cases

5 3 5
1 2 4 6 0
1 2 3
5

6 4 5
1 2 4 6 9 8
1 2 3 4
91

6 2 4
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
5 // 35-7=, other ways are 1+3*7=
9 // 62*16-11=

*/