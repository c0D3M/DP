## Plan IV  
#### Day 1  
Best Time to buy and sell stock, this is multi dimension DP, where you have option to either doSomething or doNothing and we have to max of them.  
To make it work in iterative mode, remember to start from base because thats something we know, here the base case is when day=d. 
So start from i = d-1 to 0  
skip = dp[i+1][k]  
taken = either buy or sell , these are 2 option we have on given day.  
buy = -prices[i] + dp[i+1][k]  //no new transaction is started  
sell = +prices[i] + dp[i+1[k-1]// we are making a new transaction so we need k-1 

#### Day 2 

These are like intervals are given like max profit on job scheduling for non-overlaping intervals.  
So here also, start from end where we know something i.e. if all interval are exhausted profit is 0.  
Now to get next index we have to find next index which instead of +1 do a upper_bound because next index can start after ith interval end.  

