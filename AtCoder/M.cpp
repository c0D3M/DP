#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int MAX = 1e9 + 7;
int main(int argc, char*argv[])
{
	int N, K;
	cin >> N >> K;
	vector<int> a(N+1);
	sort(a.begin(), a.end());
	vector<vector<pair<int, int>>> dp(N+1, vector<pair<int, int>>(K+1, make_pair(0, 0)));
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	
	for (int i = min(a[1],K) ; i >= 0; --i)
	{dp[1][i].first = 1;dp[1][i].second = (dp[1][i].first + dp[1][i+1].second)%MAX;}
	
	for (int i = 2 ; i <= N; ++i) //child loop
	{
		for (int j = K; j >= 0 ; --j) // candy loop
		{
			int left = a[i] > j ? 0: j-a[i];
			
			if(dp[i-1][left].first)
			{
				if(j)
				{
					dp[i][j].first += (dp[i-1][left].second)%MAX;
					if(a[i]-j)
					{
						dp[i][j].first = (dp[i][j].first - dp[i-1][K-(a[i]-j)+1].second + MAX)%MAX;
						if(dp[i][j].first<0)
							dp[i][j].first += MAX;
					}
				}
				else
					dp[i][j].first = 1;
				dp[i][j].second = (dp[i][j].first + dp[i][j+1].second)%MAX;
			}
		}
	}
	cout << dp[N][K].first;
}