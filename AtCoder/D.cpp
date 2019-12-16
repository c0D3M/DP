#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >>n>>k;
	int items[n][2];
	for (int i =0; i< n ; i++)
		cin >> items[i][0] >> items[i][1];
	vector<vector<unsigned long long>> dp(k+1, vector<unsigned long long>(n+1, 0));
	
	for (int i=1; i<=k; i++) // Iterate over the knapsack weight
	{
		for (int j= 1; j<=n;j++) // iterate all items
		{
			if(items[j-1][0]>i) // is knapsack weight good enough to hold first item?
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = max (items[j-1][1]+dp[i-items[j-1][0]][j-1], dp[i][j-1]);
		}
	}
	cout << dp[k][n];
}

