## Plan IV 
###  One Dimensional Dynamic Programming  
#### Day 1  
[123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)  

Best Time to buy and sell stock, this is multi dimension DP, where you have option to either doSomething or doNothing and we have to max of them.  
To make it work in iterative mode, remember to start from base because thats something we know, here the base case is when day=d. 
So start from i = d-1 to 0  
skip = dp[i+1][k]  
taken = either buy or sell , these are 2 option we have on given day.  
buy = -prices[i] + dp[i+1][k]  //no new transaction is started  
sell = +prices[i] + dp[i+1[k-1] //we are making a new transaction so we need k-1 

[188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)  
Same as above, start from base case i.e. i = d-1 to 0 and j loop for 1 to k transactions.  
at each day we can sell = max(doNothing , [i+1][j-1][BUY]+prices[i]  
buy = max( doNothing, [i+1][j][SELL]-prices[i].  

#### Day 2 
[1751. Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

[1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)  


#### Day 3 

[1259. Handshakes That Don't Cross](https://leetcode.com/problems/handshakes-that-dont-cross/)  

Number of hanshake: This is like fibonacci calls kind of question, f(n) = f(n-1) + f(n-2), we have to count number of ways of handshake,  
keep 2 hands fixed and then left half and right half can range between [0, 2, ...i-2]  

[1478. Allocate Mailboxes](https://leetcode.com/problems/allocate-mailboxes/)  

For bottom up , point to remember is outer loop is of k so that we can solve small problem.  
And then we loop for each index.  
For base case when k=0 (i.e. just 1 post), that case dist[0][i] is the distance.  
