#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, char*argv[])
{
	int N;
	cin >> N;
	vector<int> a(N+1);
	for (int i = 1; i<=N; ++i)
		cin >> a[i];
	long dp [N+1][N+1];
	
	for(int width = 1; width <= N; ++width)
		for (int start = 1 ; (start + width-1) <=N; ++start)
		{
			if(width == 1)
				dp[start] [start+width-1] = a[start];
			else
			{
				dp[start] [start+width-1] = max(a[start] - dp[start+1][start+width-1] , a[start+width-1]-dp[start] [start+width-2]);
			}
			
		}
	cout << dp[1][N];	
}