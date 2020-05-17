#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class HandsShaking
{
	vector<long long> dp;
	long long recurse(int n)
	{
		int l = 0;
		int r = n-2;
		long long count =0;
		while(l != n)
		{
			if(!dp[l])
				dp[l] = recurse(l);	
			if(!dp[r])
				dp[r] = recurse(r);	
			count += (dp[l] * dp[r]);
			l += 2;
			r -= 2;
		}
		
		return count;
	}
public:
	long long countPerfect(int n)
	{

		dp.reserve(n+1);
		dp.assign(n+1, 0);
		dp[0] =1;
		dp[2] = 1;
		dp[4] = 2;
		return recurse(n);
	}
};
