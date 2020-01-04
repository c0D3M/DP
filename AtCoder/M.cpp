#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define MAX (1000000007)
int main(int argc, char*argv[])
{
	int N, K;
	cin >> N >> K;
	vector<int> a(N+1);
	sort(a.begin(), a.end());
	vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	
	dp[0][0] = 1;
	//dp[1][0] = 1; // base case i.e. 1st child with
	for (int i = 1 ; i <= N; ++i) //child loop
	{
		for (int j = K; j >= 0 ; --j)
		{
			int left = a[i] > j ? 0: j-a[i];
			if(dp[i-1][left])
			{
				for(int k = min(a[i], j) ; k>=0; --k)
				{
					//if(j<k)
					//	continue;
					if(dp[i-1][j-k])
						dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MAX;
					else
						break;
				}
			}
		}
	}
	cout << dp[N][K];
}