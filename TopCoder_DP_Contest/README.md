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
   
5. [MakeSquare](https://community.topcoder.com/stat?c=problem_statement&pm=8681&rd=14426)  
6. [NoRepeatPlaylist](https://community.topcoder.com/stat?c=problem_statement&pm=11774&rd=14724)  
7. [RandomSwaps](https://community.topcoder.com/stat?c=problem_statement&pm=7289&rd=10662)  
8. [BoxTower](https://community.topcoder.com/stat?c=problem_statement&pm=6576&rd=9990)  
9. [BearPermutations](https://community.topcoder.com/stat?c=problem_statement&pm=14080&rd=16616)  
10. [DiameterOfRandomTree](https://community.topcoder.com/stat?c=problem_statement&pm=14102&rd=16627)  
