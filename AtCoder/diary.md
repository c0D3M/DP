**A Frog 1**  
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
