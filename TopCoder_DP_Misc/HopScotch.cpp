// https://community.topcoder.com/stat?c=problem_statement&pm=17401
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class HopscotchCounting {
    public:
    int count(int N)
    {  
        if(N<=2)
	    return N;
        const int mod = 1e9+7;
	vector<vector<int>> dp(N+1, vector<int>(2));
	dp[1][0] =1; dp[1][1] =1;
	dp[2][0] = 1; dp[2][1] = 1;
	for(int i =3; i <=N; ++i)
	{
		dp[i][0] = (dp[i-1][0] + dp[i-1][1])%mod;
		dp[i][1] = (dp[i-2][0]);
	}
	return (dp[N][0] + dp[N][1])%mod;
    }
};
// N= 70 ; Ans = 9736691
// 2->2, 3->3, 4->4, 5->6
// 
