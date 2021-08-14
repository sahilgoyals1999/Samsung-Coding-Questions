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

#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005];

long long solve(int arr[], int n, int p)
{
	long long ans = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}
	for (int i = n; i > 0; i--)
	{
		for (int z = 1; z <= p; z++)
		{
			if (z == 1)
			{
				dp[i][z] = (n - i + 1) * arr[i];
				continue;
			}
			for (int k = i + 1; k <= n; k++)
			{
				dp[i][z] = min(dp[i][z], dp[k][z - 1] + arr[i] * (k - i));
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, dp[i][p]);
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		int over[n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> over[i];
		}
		sort(over + 1, over + n + 1);
		cout << solve(over, n, k) << endl;
	}
	return 0;
}
