# DP
Dynamic Programming !

##### 300. Longest Increasing Subsequence  
https://leetcode.com/problems/longest-increasing-subsequence/  
LIS at each index at least of size 1.  
Start at loop from i =1 , i.e. each index.  
Checkin left side i.e. j = 0 to i (excluded) ;  
if elemnet in j is lesser than i that means we have a increasing subsequence.  
dp[i] = max(dp[i], dp[j] + 1) => we are extending the increasing subsequence by 1 at ith index.  

Return the maximum in dp array.

##### 673. Number of Longest Increasing Subsequence  [TODO]  
https://leetcode.com/problems/number-of-longest-increasing-subsequence/  
Same as above , this time we have to find "how many" longest increasing subsequence are there.  

##### 1143. Longest Common Subsequence  
https://leetcode.com/problems/longest-common-subsequence/
2 strings are given and we have to find a command subsequence.  
Create a 2D DP table 
and for each index of 2nd-string for each index of 1st string ( nested loops).  
if both characters match we are extending the common subsecquence by 1.  
   dp[i][j] = dp[i-1][j-1]+1  
otherwise, take max of  (string-1 and prev of string2, string-2 and prev of string-1)
   dp[i][j] = max(dp[i-1][j], dp[i][j-1])


##### Leetcode 1218: Longest Arithmetic Subsequence with given difference.
Key point is difference is given.  
Take a hash map for DP table  
Interate each element and see if arr[i] - difference exist in hash map or not ?
 If exist that means we are extending the Arithemtic series by 1 so just update dp[arr[i]] = dp[arr[i]-difference] + 1  
 not that means dp[arr[i]] = 1  because minimum length of any Arithemtic series can be 1.  
 Time complexity is O(n)  
 Space Complexisty is at max O(n)  
 
##### Leetcode 1027: Longest Arithmetic Subsequence. 
Same as above but no difference is given and there can be many series but we have to find the longest one.  
