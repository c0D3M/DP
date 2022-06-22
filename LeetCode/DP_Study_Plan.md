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

#### Day 3 

Number of hanshake: This is like fibonacci calls kind of question, f(n) = f(n-1) + f(n-2), we have to count number of ways of handshake,  
keep 2 hands fixed and then left half and right half can range between [0, 2, ...i-2]  

1478. Allocate Mailboxes : Top Down is easy.  
For bottom up , point to remember is outer loop is of k so that we can solve small problem.  
And then we loop for each index.  
For base case when k=0 (i.e. just 1 post), that case dist[0][i] is the distance.  
