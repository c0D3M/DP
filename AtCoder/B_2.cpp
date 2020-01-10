#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	int a[N+1];
	
	for (int i = 1; i <= N ; ++i)
		cin >> a[i];
	int dp[N+1];
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i<=N; ++i)
	{
		int k = K-1;
		dp[i]  = dp[i-1] + abs(a[i]-a[i-1]);
		for (int j = i-2; j >= 1  && k ; --j, --k)
	       dp[i] = min(dp[j] + abs(a[i]-a[j]) , dp[i] );
	}
	cout << dp[N];
}

