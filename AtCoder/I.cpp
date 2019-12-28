#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX (1000000000+7)
int main(int argc, char*argv[])
{
	int N;
	cin >> N;
	vector<double> p(N);
	vector<vector<double>> dp(N+1, vector<double>(N+1));
	for (int i=0; i<N; i++)
	{
		static double prev = 1;
		cin >> p[i];
		dp[i+1][0] = prev * (1-p[i]);
		prev  = dp[i+1][0];
	}
	/*
	dp table has coins in rows and # of heads as colums , column #0 is tails , which is calculated above
	For example : 2 coins with 1 head =  2nd coin is tails * 1st coins is head + 2nd coin is head * 1st coin is tail.
	
	*/
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
		{
			if(i==j)
				dp[i][j] = i==1? p[i-1]:  p[i-1] * dp[i-1][j-1];
			else
				dp[i][j] = (1-p[i-1])*(dp[i-1][j])+(p[i-1]*dp[i-1][j-1]) ; 
		}
	int count = (N>>1) +1;
	double res = 0;
	for (int i=count ; i<=N; i++)
		res += dp[N][i];
	printf("%.10lf", res);
}