#### Topcoder Advance DP  
Webinar:  https://www.youtube.com/watch?v=xQ4byx8XbXo  
You can practice these problem in Topcoder Arena Applet under Special Events section.  

1. [MutaliskEasy](https://community.topcoder.com/stat?c=problem_statement&pm=13782&rd=16461)  
From each state, we can go to 6 different state.  
dp[a][b][c], where a,b,c can be max 65.  
[9, 3, 1] , [9, 1, 3], [3, 9, 1] , [3, 1, 9], [1, 3, 9] , [1, 9, 3]  
Before evaluating the state, check in dp tate if it hasnt been evaluated earlier.  
Base condition: when a==0 and b==0 and c==0  
If a or b or c < 0, then call the function but set that to 0.  
This is helpful because we store dp[a][b][c] and we cant have -ve index.  
Also save each state on return.  

2. [SentenceDecomposition](https://community.topcoder.com/stat?c=problem_statement&pm=8692&rd=12183)  
We are given a target string and a dictionary, find the **least** transformation cost.  
dictionary word can be transformed to part of target string.  
Base Case: offset is greater than targetstring.  
State: Take each word(for loop) from dictionary, from the offset(starting from 0) take the substring of dictionary word size and see if we can transform.  
This can checked , sort both of them and if they are equal, transformation is possible.  
Calculate the cost and recurse by incrementing offset.  
dp state will be at each offset position.  

3. [ZigZag](https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493)  
We need to find length of Longest subsequence where number **difference** alternate +ve , -ve.  
DP State: At every index of array, we can either have +ve or -ve.  so DP[n][2].  
At every index check if number is higher than previous, if yes use previous -ve index.  
if number is lesser, use the previos index higher.  

3. [FanFailure](https://community.topcoder.com/stat?c=problem_statement&pm=2235&rd=5070&rm=&cr=8527113)  
Couln't come up DP solution.  

4. [maxDonations](https://community.topcoder.com/stat?c=problem_statement&pm=2402)  
Same as House Robber problem on Leetcode.  
Houses are placed in circle and if ith house is picked i-1 and i+1 cant be. And we have to find max donation.  
In this problem, start can be from i=0 or i=1. So caculate dp array of both and return the maximum one.
dp[i] = max(dp[i-1], nums[i] + dp[i-2]).  Either dont take donation from current house, which would mean take donation from i-1 or  
take donation from i and then we are allowed to take from i-2 as well.  
So take the max of them.  

5. [VocaloidsAndSongs](https://community.topcoder.com/stat?c=problem_statement&pm=12989&rd=15842&rm=&cr=23027795)  
Slightly tricky description,  
Key point, in each album set, all 3 singer must contribute to full capacity, only then it is counted as combination.  
"The number of songs sang by Gumi, Ia, and Mayu must be gumi, ia, and mayu, respectively."  
Sanity: if s > a+b+c , then no combination possible. return 0.  
Base condition: if s==0 , check all 3 singers exhausted there quota ? if yes return 1 , i.e. this is a valid combination else 0.  
DP state: dp[s][a][b][c] , songs to be sang, a, b, c singer quota.  
From each state, you can go a has quota , b has quota , c has quota, either 2 of them can sing same cong, all 3 can sing same song.  
Just recursively call and memoize each state.  


