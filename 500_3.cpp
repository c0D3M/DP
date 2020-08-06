#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// Time Complexity = O(n log n)
class BadNeighbors{
public:
int maxDonations(vector<int> nums)
{
	const int n = nums.size();
        
        if(!n)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> dp1(n+1, 0);
        vector<int> dp2(n+1, 0);
       
        // dp1 is taken 1 to n-1 in account
        dp1[0] = 0;
        dp1[1] = nums[0];
        for (int i = 2; i <=n-1; ++i)
            dp1[i] = max(nums[i-1] + dp1[i-2], dp1[i-1]);// Either rob this house and its 2-previous or dont rob this house that means previous-1.
        
        // dp2 is taken 2 to n in account
        dp2[0] = 0;
        dp2[1] = 0;
        dp2[2] = nums[1];
        for (int i = 3; i <=n; ++i)
            dp2[i] = max(nums[i-1] + dp2[i-2], dp2[i-1]);
        
        return max(dp1[n-1], dp2[n]);
}
};
int main(int argc, char*argv[])
{
	class BadNeighbors a;
	int ret = a.maxDonations({ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 });//19
	cout <<ret;
	return 0;
}
