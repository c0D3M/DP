#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// Time Complexity = O(n log n)
#define MOD 1000000007

#define MAXN 56
int dp[MAXN][MAXN][MAXN][MAXN];
class VocaloidsAndSongs{
	int solve(int s, int a, int b, int c)
	{
		if(s > a+b+c)
			return 0;
		if(s==0)
		{
			if(a+b+c==0)
				return 1;
			return 0;
		}
		int &ret = dp[s][a][b][c];
		if(ret != -1)
			return ret;
		ret  = 0;
		if(a) ret = (ret + solve(s-1, a-1, b, c))%MOD;
		if(b) ret = (ret + solve(s-1, a, b-1, c))%MOD;
		if(c) ret = (ret + solve(s-1, a, b, c-1))%MOD;
		if(a and b) ret = (ret + solve(s-1, a-1, b-1, c))%MOD;
		if(a and c) ret = (ret + solve(s-1, a-1, b, c-1))%MOD;
		if(c and b) ret = (ret + solve(s-1, a, b-1, c-1))%MOD;
		if(a and b and c) ret = (ret + solve(s-1, a-1, b-1, c-1))%MOD;
		return ret;
	}
public:
int count(int S, int gumi, int ia, int mayu)
{
	memset(dp, -1, sizeof dp);
	return solve(S, gumi, ia, mayu);
}
};
int main(int argc, char*argv[])
{
	class VocaloidsAndSongs a;
	int ret = a.count(18, 12, 8, 9);//19
	cout <<ret;
	return 0;
}
