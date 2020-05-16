#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class NumberofFiboCalls
{
public:
vector <int> fiboCallsMade(int n)
{
int dp [n+1][2];
dp[0][0] = 1;
dp[0][1] = 0;
dp[1][0] = 0;
dp[1][1] = 1;
for (int i =2; i<=n; ++i)
{
	dp[i][0] = dp[i-1][0]+dp[i-2][0];
	dp[i][1] = dp[i-1][1]+dp[i-2][1];

}
return vector<int> {dp[n][0], dp[n][1]};
}
};
