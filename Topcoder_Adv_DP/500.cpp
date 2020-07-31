#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55
unsigned int dp[MAX_N];

class ZigZag{

public:
int longestZigZag(vector <int> sequence) 
{
	int n = sequence.size();
	if(n==1)
		return 1;
	int dp[n][2];
	for (int i = 0; i < n ; ++i)
	{
		dp[i][0] = 1;
		dp[i][1] = 1; 
	}
	int answer = INT_MIN;
	
	for (int i = 1; i < n ; ++i)
	{
		if(sequence[i] > sequence[i-1])
		{
			dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
			dp[i][0] = dp[i-1][0];
		}
		else  if(sequence[i] < sequence[i-1])
		{
			dp[i][0] = max(dp[i][0] , dp[i-1][1] +1);
			dp[i][1] = dp[i-1][1];
		}
		else
		{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
		}
		answer = max({answer, dp[i][0], dp[i][1]});
	}
	return answer;
}
};
int main(int argc, char*argv[])
{
	class ZigZag a;
	//cout << a.longestZigZag({1, 7, 4, 9, 2, 5}); // 6
	//cout << a.longestZigZag({1, 17, 5, 10, 13, 15, 10, 5, 16, 8}	); // 7
	//cout << a.longestZigZag({10, 9, 8, 7, 6, 7, 8, 9, 10}		); // 3
	//cout << a.longestZigZag({4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}); // 3
	
	//cout << a.longestZigZag({12, 333, 700, 436, 1, 919, 959, 456, 456, 456, 1000, 193, 192, 13, 75, 818, 197, 197, 2, 777, 99, 81, 222, 109, 1000, 19, 27, 270, 62, 189, 987, 234, 55, 2, 718, 238, 901, 901, 900, 432, 55, 606, 89, 7, 7, 23, 789, 790, 800, 1000}); // 26
	cout << a.longestZigZag(	{61, 82, 126, 97, 167, 186, 119, 154, 155, 142, 153, 181, 172, 192, 223, 272, 273, 260, 280, 330, 329, 350, 273, 324, 349, 306, 385, 375, 420, 416, 435, 457, 373, 477, 395, 487, 500, 439, 493, 537, 518, 549, 542, 500, 524, 541, 512, 589, 549, 543}); // 35
	return 0;
}
