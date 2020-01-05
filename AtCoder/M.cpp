#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int main(int argc, char*argv[])
{
	int N, K;
	cin >> N >> K;
	vector<int> a(N+1, 0);
	vector<vector<pair<int, int>>> dp(N+1, vector<pair<int, int>>(K+1, make_pair(0, 0)));
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	
	for (int i=0; i<=K ; ++i)
	{
		dp[0][i].first = 1;
		dp[0][i].second = 1;
	}
		
	for (int i = 1 ; i <= N; ++i) //child loop
	{
		for(int j = 0; j <= K; ++j)
        {
            int left = j, right = (j - a[i] - 1);

            dp[i][j].first = dp[i - 1][left].second;

            if(right >= 0)
            {
                dp[i][j].first = sub(dp[i][j].first , dp[i - 1][right].second);
            }
			if(j)
				dp[i][j].second = add(dp[i][j].first, dp[i][j-1].second);
			else
				dp[i][j].second = dp[i][j].first;
        }
	}
	cout << dp[N][K].first%MOD;
}