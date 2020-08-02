#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55
unsigned int dp[MAX_N];
// Time Complexity = O(n log n)
class FanFailure{

public:
vector <int> getRange(vector <int> capacities, int minCooling)
{
	sort(capacities.begin(), capacities.end());
	int totalSum = accumulate(capacities.begin(), capacities.end(), 0, std::plus<int>());
	// but we need just minCooling , so count of Fans which sums <=  totalSum - minCooling can be failure set.
	int n = capacities.size();
	int sum = 0;
	int r1=0;
	for (int i = 0 ; i < n ; ++i)
	{
		if(sum + capacities[i] <= totalSum - minCooling)
		{
			sum += capacities[i];
			++r1;
		}
		else
			break;
	}
	cout << r1;
	// Now lets see if we start removing maxFan capacity , if the remain can handle minCooling ?
	sum = 0;
	int r2=0;
	for (int i = n-1 ; i >=0 ; --i)
		if(totalSum - (sum + capacities[i]) >= minCooling)
		{
			sum += capacities[i];
			++r2;
		}
		else
			break;
		
	return vector<int> ({r1, r2});
	
}
};
int main(int argc, char*argv[])
{
	class FanFailure a;
	vector<int> ret = a.getRange({676, 11, 223, 413, 823, 122, 547, 187, 28}, 1000);
	return 0;
}
