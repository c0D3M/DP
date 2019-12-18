#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
bool sortByWeight(pair<unsigned long long, unsigned int> &a, pair<unsigned long long, unsigned int> &b)
{
	return a.first < b.first;
}

int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	unsigned int N; 
	unsigned long long W;
	cin >>N>>W;
	vector<pair<unsigned long long, unsigned int>> items;
	unsigned int total_v =0;
	unsigned int max_val = 0;// used to store result;
	for (int i =0; i < N; i++)
	{
		unsigned long long w;
		unsigned int v;
		cin >>w>>v;
		total_v += v;
		items.push_back(make_pair(w, v));
	}
	vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(total_v+1, -1));
	
	//Sort the items by weights
	sort(items.begin(), items.end(), sortByWeight);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= total_v; j++)
		{
			if( j >= items[i].second)
			{
				unsigned long long not_taken = dp[(i-1)&1][j]; // item is is not taken 
				unsigned long long taken = items[i].first;
				if(j > items[i].second) // Left over value after taking ith item
					if((dp[(i-1)&1][j-items[i].second]!=-1))
						taken += dp[(i-1)&1][j-items[i].second];
					else
					{dp[i&1][j] = not_taken ;continue;}
				
				if(taken> W)
					continue;
				dp[i&1][j] = taken;
				
				if(not_taken !=-1)
				    dp[i&1][j] = min(dp[i&1][j], not_taken);
				if(max_val < j)
					max_val = j;
			}
			else
				dp[i&1] [j] = dp[(i-1)&1][j];
		}
	}		
	cout << max_val;
}

