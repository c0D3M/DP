#include <bits/stdc++.h>
#include <algorithm>
#define MAX 307
using namespace std;
double dp[MAX+5][MAX+5][MAX+5]; // Hold expectation value for each state.
int main(int argc, char*argv[])
{
	int N;
	cin >> N; // N can be between 1 to 300
	// Each of the Sushi plat can have  1 to 3 Sushi max
	
	vector<int> cnt(4, 0);// We count how many Sushi plates with 1-sushi, 2-sushi and 3-sushi.
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >>t;
		++cnt[t];
	}
	for (int i = 0; i <= MAX; ++i) // Loop for 3 Sushi
		for (int j = 0; i + j <= MAX; ++j)// Loop for 2 Sushi
			for (int k = 0; i + j + k <= MAX; ++k)// Loop for 1 Sushi
			{
				if(i ==0 && j==0 && k==0) //All Sushi over
					continue;
				if(i+j+k > MAX) // Sushi count > N , not possible
					continue;
				
				double K = 1.0 * ( k + j + i); // Total plates with 1-2-3 Sushi 
				
				
				// Add the expectation of choosing plate with 1 Sushi , multiply with probability of choosing 1 over total (K)
				if(k) // if count#1 is !=0
					dp[k][j][i] += ((1.0 * k)  /K ) * dp[k-1][j][i]; 
				
				if(j) // if count#2 is !=0; if plate with 2-sushi is choosen and 1 is eaten , 2-sushi plate will decrease, 1-sushi plate will increase
					dp[k][j][i] += ((1.0 * j)  /K )* dp[k+1][j-1][i]; 
				
				if(i) // if count#3 is !=0; if plate with 2-sushi is choosen and 1 is eaten , 3-sushi plate will decrease, 2-sushi plate will increase
					dp[k][j][i] += ((1.0 * i)  /K )* dp[k][j+1][i-1];
					
				// This is the expectation that we hit a plate which is empty , add expectation of that as well.
				// E = 1/p ; 
				dp[k][j][i] += (1.0 *N)/K;	
			}
			
	cout.precision(15);
    cout << fixed << dp[cnt[1]][cnt[2]][cnt[3]] << "\n";
}