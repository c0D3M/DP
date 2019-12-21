#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, t;
	cin >> s>>t;
	
	// lets keep s as smaller string
	if(s.size()>t.size())
		swap(s,t);
	int n_s = s.size();
	int n_t = t.size();
	vector<vector<string>>  dp(2, vector<string>(n_s+1, ""));
	for (int i = 0 ; i < n_t ;i++)
	{
		for(int	j = 1; j < n_s+1; j++)
		{
			// Take the item 
			string taken;
			
			// If last character are matching , take that, and now since 'i'the index cant be matched, take dp of prev index 
			if(t[i] == s[j-1])
			{
				taken = dp[(i-1)&1][j-1];
				taken += t[i];
			}
			// If they arent matching then either(max) take current index or previous
			else
			{
				
				if(dp[(i-1)&1][j-1].size() > dp[i&1][j-1].size() )
					taken = (dp[(i-1)&1][j-1]);
				else 
					taken = (dp[i&1][j-1]);
			}
			
			// dont take the ith index 
			string not_taken(dp[(i-1)&1][j]);
			dp[i&1][j] = taken.size()>not_taken.size()?taken:not_taken;
		}
	}
	//cout <<dp[!(n_t&1)][n_s].size();
	cout <<dp[!(n_t&1)][n_s];
}