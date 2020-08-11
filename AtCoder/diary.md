**A. Frog 1**  
Frog is at Stone 1.  
Frog can make 2 of the possible move +1 or +2.  
Cost of each move is |hi - hi+1|  

Approach:  
Set a dp[N+1]  
with dp[0] = INF
Iterate a look from 2 to N.  
At each step it can either come from i-1 or i-2 previous stone.  
Take min of it.  

Time Complexity = O(n)  
Space Complexity = O(n)  
**B. Frog 2**  
Same as earlier problem, except instead of 2 moves, there are K moves.  
So for each step starting from 2, check which is the cheapest jump, run a loop of K to 0.  

**C. Vacation**  
Base case : start with last i.e. set dp[n][0] = f[n][0]....
Now interate from n-1 to 0, if he choose Activity 0, next daya i.e. i+1, he can choose max of dp[i+1][1], dp[i+1][2].  
And same for other 2 activity for each day.  
Like that keep progresing backward.  
Answer would be max of 3 activity of Day 0.  

**D. Knapsack**  
Create a 2-D DP Array, DP[W][N]  
In Nested for loop, outer loop for weigth and inner for items.  
If weight > item ; just copy previous dp.
else we have a choice, either take the item + left over weigth , or dont take the item.  
dp[i][j] = max(dp[i][j-1], item[j][1] + dp[i-item[j][0]][j])  

**E. Knapsack 2**  
Now W is 10^9, and the runtime can be longer.  
Further we are unnecessaryily iterating for each weights , which may not be useful.  
V is smaller, so lets make DP table of V and further we store only 2 rows of DP to optimize of memory.  
Note that previous state of DP has memory of all the other previous states.  
So it is sufficient to keep just previou state and work on current state and flip between two of them.  
So we iterate the items:  
   Iterate the value:
     if value of ith item is less than current value;
        see whats the minimum weight to get the required value.  
        
**F. LCS**
for each index of string1 , we iterate string2. 
Either string1 and string 2 match at the given index : dp[i][j] = 1 + dp[i-1][j-1]; since we are extending the LCS by 1.  
If not: dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ; LCS would either string1 match previous string2 or vice versa.  

**G. Longest Path**  
Graph based.  

**H. Grid 1**  
Same as Maximum Falling Sum.  

**I. Coins**  
N coins and each has probability of coming head as input.  
More heads than tail.  
dp table has coins in rows and # of heads as colums , column #0 is tails , which is calculated above during processing input.  
For example : 2 coins with 1 head =  2nd coin is tails * 1st coins is head + 2nd coin is head * 1st coin is tail.  

In the end for last coin , sum all n/2 + 1 to n head columns, since only then we have more head than tail.  
**A. Frog 1**  
