#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX_N 105
long long dp[MAX_N][MAX_N];
class AvoidRoads {
    string conString(int a, int b, int c, int d)
    {
        string s = to_string(a);
        s += " " + to_string(b) + " " + to_string(c) + " " + to_string(d);
        return s;
    }
    bool isAllowed(string seg, vector<string> bad)
    {
		if(!bad.size())
			return true;
        if(find(bad.begin(), bad.end(), seg)!= bad.end() )
            return false;
        else
            return true;
    }
    public:
    long long numWays(int width, int height, vector <string> bad)
        {
        	memset(dp, 0, sizeof dp);
			dp[0][0] = 1;
        	
            for(int i = 0; i <= width; ++i)
                for(int j = 0; j <= height; ++j)
                {
					if(i>0)
                	if(isAllowed(conString(i-1, j, i, j), bad) and isAllowed(conString(i, j, i-1, j), bad) )
                        dp[i][j] += dp[i-1][j];
					if(j>0)
                	if(isAllowed(conString(i, j-1, i, j), bad) and isAllowed(conString(i, j, i, j-1), bad))
                        dp[i][j] += dp[i][j-1];
                }
        	
        	return dp[width][height];
        }
};
int main(int argc, char*argv[])
{
	class AvoidRoads a;
	int ret = a.numWays(6,6,{"0 0 0 1","6 6 5 6"}); //252
	//long long ret = a.numWays(31,35,{}); //6406484391866534976
	cout <<ret;
	return 0;
}
