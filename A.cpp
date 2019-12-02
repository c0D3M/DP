#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >>n;
	int jump[n];
	for (int i =0; i< n ; i++)
		cin >> jump[i];
	int dp [n][3];
	dp[0] [1] = abs(jump[0] - jump[1]);
	if(n>2)
		dp[0] [2] = abs(jump[0] - jump[2]);
	for (int i = 1 ; i< n-1; i++)
	{
		dp[i][1] = min( (dp[i-1][1] + abs(jump[i] - jump[i+1])), dp[i-1][2]   );
		if(i+2 < n)
			dp[i][2] = dp[i-1][1]+ abs(jump[i] - jump[i+2]);
	}
	cout << dp[n-2][1]<<endl;
}

