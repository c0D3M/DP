#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, char*argv[])
{
	int N, K;
	cin >> N >> K;
	vector <int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	
	vector<bool> dp(K+1);
	// lets starts with 0-stones and iterate upto K
	for (int i = 0; i <=K; ++i)
		for (auto & j: a) // iterate over all possible moves
			if(i>=j && !dp[i - j])
				dp[i] = true; // This means Taro is winning because Taro has taken 'j' stones and also left over stone dp[i-j] is false
	
	if(dp[K])
		cout << "First";
	else
		cout << "Second";
}