#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18+5;
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
	int N;
	cin >> N;
	vector<int> a(N+1, 0);
	vector<vector<long  long>> dp(N+1, vector<long long>(N+1, 0)); // value of ith index and slime cost
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	vector<long long> sum(N+2, 0);
	sum[N] = a[N];
	for (int i = N-1; i >= 1; --i)
		sum[i] = sum[i+1] + a[i];
	
	// Create pair of each 
	for (int L = N; L >= 1; --L)
		for (int R = L; R<=N; ++R)
		{
			if(R==L)
				dp[L][R] = 0;
			else{
				dp[L][R] = INF;
				for (int i = L; i<R; ++i)
					dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + sum[L]-sum[R+1]);
			}
			
		}
	
	cout << dp[1][N];
}