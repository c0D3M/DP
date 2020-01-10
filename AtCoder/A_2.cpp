#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >>N;
	int a[N+1];
	a[0] = 1e+5;
	for (int i = 1; i <= N ; ++i)
		cin >> a[i];
	int dp[N+1];
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i<=N; ++i)
	       dp[i] = min(dp[i-2] + abs(a[i]-a[i-2]) , dp[i-1] + abs(a[i]-a[i-1]));
	cout << dp[N];
}

