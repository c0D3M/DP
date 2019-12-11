#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	//vector<vector<int>> f(n, vector<int>(3));
	int f [n][3];
	int dp[n][3];
	for (int i =0; i< n; i++)
		for (int j= 0; j <3; j++)
			cin >> f[i][j];
	
	dp[n-1][0] = f[n-1][0];
	dp[n-1][1] = f[n-1][1];
	dp[n-1][2] = f[n-1][2];
	for (int i =n-2 ; i>=0; i--)
	{
		dp[i][0] = f[i][0] + max (dp[i+1][1], dp[i+1][2]);
		dp[i][1] = f[i][1] + max (dp[i+1][0], dp[i+1][2]);
		dp[i][2] = f[i][2] + max (dp[i+1][0], dp[i+1][1]);
	}
	
	cout << max(dp[0][0], max(dp[0][1], dp[0][2]));
		
}

