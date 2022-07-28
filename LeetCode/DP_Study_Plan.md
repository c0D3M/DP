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
Here one twist is you can attend k events  
So start from i= n-1, and here we have to loop for j = 1 to k events , either skip that means dp[i][j] = dp[i+1][j]
or attend event that meand event_cost +dp[i+1][j-1] (since we are attending 1 event now).  

[1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)  
Start from i = n-1 to 0 because we know about the base case i.e. when all events are taken dp[n] = 0  

Skip or Taken approach  
If Skip we take dp[i+1]  
if we take this job then we can take any job starting after this job end time , so we have to search on the right side , we use upperb_bound for this.  
Take maximum of skip or taken.  


#### Day 3 

[1259. Handshakes That Don't Cross](https://leetcode.com/problems/handshakes-that-dont-cross/)  

Number of hanshake: This is like fibonacci calls kind of question, f(n) = f(n-1) + f(n-2), we have to count number of ways of handshake,  
keep 2 hands fixed and then left half and right half can range between [0, 2, ...i-2]  

[1478. Allocate Mailboxes](https://leetcode.com/problems/allocate-mailboxes/)  

First we calculate distance dist[i][j] which means if the mainbox is kept between i & j whats the total distance from all house.  
Then we start at index 0 and k mailboxes.
At each index , we try to put mailbox from index to n  and then recursively solve.
Stop condition if k==0 and i==n , we have placed everything so return 0.  
Either i==n or k==0, that means we run out of mailboxes or index , thats not good 

#### Day 4  

[32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)  

Only when we encounter closed braces i.e. ```)```  
 - Either i-1 is open ```(```  , if yes we know we extend dp[i-2] + 2
 - If i-1 is ```)``` that means ```(())``` kind of scenario  
   find if dp[i-1] is non-zero that means something we can extend so go back ```i - dp[i-1] -1``` , this gives index of first ```(```  
   dp[i] = dp[i-1] + 2 + anything before first index i.e. ```i - dp[i-1] -2```

[1105. Filling Bookcase Shelves](https://leetcode.com/problems/filling-bookcase-shelves/)  

ith book can be placed on new row , in that case height is dp[i-1] +  height  
or it can be placed with all previous books i.e. i-1 to 1 books , height shd be maximum between them and all this shd happen until width is available .  

###  Dynamic Programming on Counting

#### Day 5  

[1277. Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)  

For each non-zero element , We check left, top and corner and pick minimum of them ,  all those wil get extended by 1 , morever we set matrix[i][j] to this value,
so that further we can know how many sub matrix to be extended.  

[361. Bomb Enemy](https://leetcode.com/problems/bomb-enemy/)  

We recompute row based or col based only when  i=0 or j=0 or previous cell(top or left) was W.  
Then for every blank cell we see if row + cold[j] > ans, set as ans.  




