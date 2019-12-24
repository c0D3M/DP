#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX (1000000000+7)
int main(int argc, char*argv[])
{
	
	vector<string> a;
	int H, W;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> H >> W;
	vector<vector<unsigned int>> dp(H, vector<unsigned int>(W));
	a.reserve(H);
	
	for (int i = 0; i< H; i++)
	{
		string s;
		cin >> s;
		a.push_back(s);
	}
	dp[0][0] = 1;
	for (int i = 0; i< H;i++)
		for (int j =0; j < W; j++)
		{
			if(a[i][j]=='#')
				continue;
			if( j-1 >= 0 ) dp[i][j] += dp[i][j-1]%MAX;
			if( i-1 >= 0 ) dp[i][j] += dp[i-1][j]%MAX;
		}
	
	cout <<dp[H-1][W-1]%MAX;
}