**464. Can I Win**  
Rules of Game:  
- Can chose any number between 1 to maxChooseable.  
- Already chosen number can be chosen again.  
- The player who make the sum >= targetSum wins.  

Steps:  
Maintain bitmask of numbers being used or not.  
Also maintain running sum.  
Iterate 0 to maxChooseable.
Check if bitmask is 0, that means this number is free to be chosen.
if sum + i >= targetSum, we can win. return true.  
Otherwise we want opponent to loose and only in the case opponent return false we can win.  
Opponent will also use best strategy.  

Memoization:
dp state would be what all numbers haven been chosen, since maxChooseable can be 20, bitmask can be used and this bitmask can be stored in hasmap.  


**494. Target Sum**  
We are given an array and a target sum, we can use +/-.   
Need to find how many ways target sum can be achieved.  

At each array index, we can either do + or -, which will accordingly increase or decrease sum.  
if at the last index we achieve the target sum then this is a combination otherwise not.  
For dp memoization, used sum and array index. Now sum can be -ve number as well, so used map.
Although it gives AC but explore better ways.  

**698. K-subset**  
We need to partition the array into k-subset such that sum is equal for each k-subset.  
Target sum = Total Sum /K;
Take an index which is not occupied earlier, since # of element is 16 , we can use bitmap.  
Also the total sum <= target_sum.  
if we achieved the target then recurse further and find next subset, we need to find k subset, when k=0, that means  we got it.  
Memoization:  State would be what all element of index are taken and how many subset are formed so far. Using map for this.  


**268. Largest Divisible Set**  
Find the largest subset such that each divide.  
Used dp[n] to store length of subarray which can divide at this index, initialize with 1 since each number can divide itself.  
dp_r[n] stores index which is getting extended.  
Sort the numbers.  
Start a nested loop like LIS.  
if numbers are divisble 
  check if j+1 > i
    if yes we got a better answer for i, updated dp[i] = dp[j]+1 and also dp_r[i] = j;  
    later dp_r is used to with element , since we haev to return the set not the size.  
  if dp[i] > answer
    update answer 

**1155. Number of dice roll**  
*d* dices *f* faces and *target* is given, how many ways to achieve.  
Sanity check (d * f < target) then not possible.  
At each dice roll, find whats the max and minimum a dice can roll.  
For example if target is 3 and dice has 6 faces, minimum dice can roll is 1 and maximum it can 3.  
Start a loop of min to max.  
recurse with decreased target and 1 less dice roll.  

If we are at last dice , we can surely achieve the target so return 1.  
Note that sanity check of target not been achieve has already been done beofre this check.  
dp state is # dice left and # target left to achieve.
Problem statement gave a hint as well that d is 30 and target sum is 1000, hence a dp array is possible.  


**212. Maximal square**  
Need to find largest square inside a matrix.  
By definition each cell of matrix is a square. This can be extended if left, right and diagnoal are all 1.  
In a nested for loop, keep looking for this condition.  

**576. Out of Boundary**  
Given a grid and a ball and we need to find how many way the ball be out of boundary in atmost **N** moves.  
Possible moves are +/-1 on any side, and also the ball can occupy the same position.  

Recursively take all the moves.  
Memoization: Variable condition here is [i,j] index and moves count N.
so dp[i][j][N], as per problem state i, j, N can be max 50.  

**122. Buy Sell Stocks-2**  
Multiple transaction of buy-sell and get max profit.  

So we keep track of lowest price find so far in dp array at each index. The moment we find a higher price at this indx > dp[i-1].  
Sell it and dp[i] = price[i], now the aim is to find anything max than this.

**121. Buy Sell Stocks-1**  
dp array record minimum found so far.
dp[0] = array[0].  
Start with index 1,
if price at i < dp[i-1]
  dp[i] = price[i]
else
   dp[i]=dp[i-1] // because we now going to sell and dp[i] = dp[i-1]
   update answer as max(answer, price[i] - dp[i-1])
   
