#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >>n>>k;
	int jump[n];
	for (int i =0; i< n ; i++)
		cin >> jump[i];
	int dp [n][k+1];
	
	
	for(int i = 1; i <= min(n, k); ++i)
		dp[0] [i] = abs(jump[0] - jump[i]);
		
	for (int i = 1 ; i< n-1; ++i)
	{
		for (int j= 1 ; j < k; ++j)
			dp[i][j] = min( (dp[i-1][1] + abs(jump[i] - jump[i+j])), dp[i-1][j+1]);
		if(i+k < n)
			dp[i][k] = dp[i-1][1]+ abs(jump[i] - jump[i+k]);
	}
	cout << dp[n-2][1]<<endl;
}

