**TopCoder Dynamic Programming Webinar**  
Date: 14th May 2020

Practice Match:
https://www.topcoder.com/tc?module=MatchList  

Resources:  
https://apps.topcoder.com/forums/?module=Thread&threadID=955677&start=0  

https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/  

1. [NumberofFiboCalls](https://community.topcoder.com/stat?c=problem_statement&pm=2292&rd=10709)  
Objective of problem is to find how many time {0, 1} would have been called to find n-th(input) fibonacci.  
Iterative we can build the dp array.  
For each number we will maintain number of {0} and {1}.  
Base case is for n=0 {0}= 1 and {1}=0.  
n=1 {0}= 0 and {1}=1.  
```
vector <int> fiboCallsMade(int n)
{
 	vector<vector<int>> dp(n+1, vector<int>(2));
 	dp[0][0] = 1;
 	dp[0][1] = 0;
    if(n!=0)
    {

        dp[1][0] = 0;
        dp[1][1] = 1;

        for(int i =2; i <=n; ++i)
        {
           dp[i][0] = dp[i-1][0] + dp[i-2][0];
           dp[i][1] = dp[i-1][1] + dp[i-2][1];
        }
    }
    return dp[n];
}

```
2. [EmoticonsDiv2](https://community.topcoder.com/stat?c=problem_statement&pm=13041&rd=15845)  
Key idea is for smaller sub-problem find the optimal solution by seeing how many ways it can be perfectly divided.  
For odd number it is always same way as they cant be divided.  
For example if n=8 , see if 8 can be divided [2,4] , see the cost of 2 and 1 copy + 3 paste which is 4.  
So total cost is dp[2] + 8/2  
```
int printSmiles(int n)
{
    vector<int> dp(n+1, 0);
    iota(dp.begin(), dp.end(), 0);
    dp[1] = 0;
    for(int i = 2; i <=n ; ++i)
        for(int j = 1 ; j <=i ; ++j)
    		if((i%j)==0)
    			dp[i] = min(dp[i], dp[j]+(i/j));
    return dp[n];
}
````

3. [HandsShaking](https://community.topcoder.com/stat?c=problem_statement&pm=7868&rd=10777)  
n is even.  
base case, if n = 0 dp[0] = 1, n=2 dp[2] = 1, n=4 dp[4] = 2.  
My approach is is to recursively split 'n' into 0 and n-2.  
Why n-2 because we are keeping 2 people fixed and left half is 0 and right half is n-2.  
then we increment left half by2 and decrement right by 2 and keep doingt left != right.  
Before recurse check if dp result is available or not.  
Iterative Method  
```
	long long countPerfect(int n)
	{
		vector<long long > dp(1+n, 0);
		dp[0] = 1;dp[2] = 1;dp[4] = 2;
		for(int i =6 ; i <=n ; i+=2)
		{
			for(int j =0; j <=i-2; j=j+2)
			{
				dp[i] += (dp[j] * dp[i-2-j]);
			}
		}
		return dp[n];
	}

```


4. [MonstersAndBunnies](https://community.topcoder.com/stat?c=problem_statement&pm=8595&rd=12007)
Observation:  
   - If monsetr is 0, you wont die for sure , so retun 1.  
   - If monster is odd, sure you will die , so return 0.
   - If monster is even, unfavourable fight wth monster are M. Total fiught among monster are (M * (M-1))/2  
     because 1st monster can fight M-1 , 2nd can M-2 so total would be (AP sum).  
     Hence Total Fight  = M + (M * M-1)/2  
     Favourable are M * (M -1)/2  i.e. monster fight among themselves.  
     Hence Probability would be 1/ (1+M)
```
double survivalProbability(int M, int B)
{
    (void)B;
	if(M%2==0) // Even
	{
		return 1.0 / (1.0 + M);
	}
	return 0.0;
}
```
   
5. [MakeSquare](https://community.topcoder.com/stat?c=problem_statement&pm=8681&rd=14426)  
This is same as Edit Distance problem on LC but on every index.  
```
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAXN 55
int dp[MAXN][MAXN];
class MakeSquare{
    int solve(string s1, string s2)
        {
            // If s2 is empty we need s1 size of changes surely
        	for(int i =0; i <=s1.size(); ++i)
                dp[0][i] = i;
        	for(int i =0; i <=s2.size(); ++i)
                dp[i][0] = i;
            for(int i =1; i <=s2.size(); ++i){
                for(int j =1; j <=s1.size(); ++j){
                    if(s2[i-1]==s1[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    else
                        {
                              //Erase
                              dp[i][j] = 1 + dp[i][j-1];
                              // Replace
                              dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
                              // Insert                                
                              dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
                        }
                } // End of Inner Loop
            }// End of Outer Loop
            return dp[s2.size()][s1.size()];
        }
    public:
     int minChanges(string S){
         int l = S.size();
         
         int ans = INT_MAX;
         for(int i= 0; i <=l; ++i)
             {
             string s1 = S.substr(0, i);
             string s2 = S.substr(i);
             ans = min(ans, solve(s1, s2));
             }
         return ans;
         
     }
};
```
6. [NoRepeatPlaylist](https://community.topcoder.com/stat?c=problem_statement&pm=11774&rd=14724)  
```
    int numPlaylists(int N, int M, int P)
    {
        const long long mod = 1e9+7;
        vector<vector<long long >> dp;
        dp.resize(1+P, vector<long long >(1+N, 0));
        // We need to create a playlist of P songs
        dp[0][0] = 1; // if there are 0 songs available and a playlist of 0 size is always possible in 1 way
        for(int i =1 ; i <=P ; ++i)
        {
            // When constructing ith song we have N-(j-1) choices, since j-1 are already picked up in i-1 
            for(int j = 1; j <=N; ++j)
            {
                dp[i][j] = (dp[i-1][j-1] * (N- (j-1))) % mod;// At this jth song selection we have N- (j-1) available
                if(j>M)
                dp[i][j] = (dp[i][j] + (dp[i-1][j] * (j-M))) % mod;// these songs are now available for reselection for example if we have selected 1st song and M =2, at j=3 , this first song is available again.
            }
        }
        return (int)dp[P][N];
    }
```
7. [RandomSwaps](https://community.topcoder.com/stat?c=problem_statement&pm=7289&rd=10662)  
```
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class RandomSwaps
{
public:
double getProbability(int N, int swapCount, int a, int b)
{
    vector<vector<double>> dp(2, vector<double>(1+swapCount, 0));
    /*
    dp[0] holds probability that a coems to b
    dp[1] holds probability that a doesnt comes to b
    */
    if(a==b)
    	dp[0][0] = 1.0; // since at begining a is same as b so probabilty is 1 with 0 swapcount
    else
    	dp[1][0] = 1.0; // since at begining a is not same as b so probabilty is 1
    // AP means sum of n number
    // Total swap are AP(N-1) i.e. N=4 ...a.b , a.c, a.d, b.c, b.d, c.d = 6 i.e. AP(3)
    for(int i =1; i<=swapCount; ++i)
    {
      // a remain b 
      // this can be achived in 2 aways from dp[0][i-1]
      // 1st way is dp[0][i-1] remain as is and rest AP(n-2) swap amoung themselves /AP(N-1) Probab = AP(N-2)/AP(N-1) = N-2/2
      dp[0][i] = dp[0][i-1] * (N-2) / N ; // remain in target from target
      // Another possibility is a can come to b from dp[1][i-1] that will be exactly 1 way to do so 1 / AP(N-1)
      dp[0][i] += dp[1][i-1] * ( 2.0 /(N*(N-1) ) ); // remain in target from off target
      // For dp[1][i]
      // N-1 ways to off target from target N-1 / AP(N-1) = 2 / N;
      dp[1][i] = dp[0][i-1] * 2.0 / N ;
      // Remain off target from off target , which is calculated as 1 - (n-1 / AP(N-1)) , since n-1 way to come to target , 
      dp[1][i] += dp[1][i-1] *  (1.0 - 2.0 / N / (N - 1));
      
    }	
    return dp[0][swapCount];
}

};
```
8. [BoxTower](https://community.topcoder.com/stat?c=problem_statement&pm=6576&rd=9990)  
9. [BearPermutations](https://community.topcoder.com/stat?c=problem_statement&pm=14080&rd=16616)  
10. [DiameterOfRandomTree](https://community.topcoder.com/stat?c=problem_statement&pm=14102&rd=16627)  
