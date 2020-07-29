#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 65
int dp[MAX_N][MAX_N][MAX_N];
class MutaliskEasy
{
int solve(int a, int b, int c)
{
	// Since we are storing states in dp array and a,b,c can go -ve which will be not be able store so limit to 0.
	if( a < 0) return solve(0, b, c);
	if( b < 0) return solve(a, 0, c);
	if( c < 0) return solve(a, b, 0);
	
	// Now check if we have already evaluated the state?
	int &ans = dp[a][b][c]; // nice way to stop using dp[a][b][c] everywhere ...
	if(ans != -1)
		return ans;
	
	if(!a and !b and !c) // we are done
		return 0;
	// Othewrise a,b,c can each take 9,3,1
	ans = INT_MAX;
	// Go to next sub-problem , after return add +1 because we already taken this step.
	ans = min (ans , 1 + solve(a-9, b-3, c-1));
	ans = min (ans , 1 + solve(a-9, b-1, c-3));
	ans = min (ans , 1 + solve(a-3, b-9, c-1));
	ans = min (ans , 1 + solve(a-3, b-1, c-9));
	ans = min (ans , 1 + solve(a-1, b-3, c-9));
	ans = min (ans , 1 + solve(a-1, b-9, c-3));
	
	return ans;
		
}
public:
int minimalAttacks(vector <int> x)
{
	memset(dp, -1, sizeof dp);
	while(x.size() != 3)
		x.push_back(-1);
	return solve(x[0], x[1], x[2]);
}
};
int main(int argc, char*argv[])
{
	// 1 31 21
	class MutaliskEasy a;
	cout << a.minimalAttacks({1,40,24});
	//cout << a.minimalAttacks({37, 15});
	return 0;
}
// 1,40,24 , exp=6 got=10