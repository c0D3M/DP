**1563. Stone Game V**
Objective of the game is to sub-divide the array into 2 halves and then throw the half whose sum is higher.  
Recurisvely keep doing this until there is just 1 row left.  
Base condition:  
- If there is just 1 item in array, return 0, that can be achieved by l-r==0, where l and r are left and right index.  
- Additionally if l-r==1 , that means just 2 items in array, return minium of it.  

DP memoization:  
At each state we have array which is bounded by l and r values,this can serve as dp state.  

Logic:  
So at each state , iterate all possible subdivision and get the sum of that subdivision.  
sum can be achieved via prefix sum method.  
Take the minium of left or right sum and recurse further on minimum subarray with updated values of l and r.  
If left and right sum are equal , in that case recurse on both left half and right half and take maximum of it.  


**1510. Stone Game IV**
Similar to earlier problem but here instead of accumulation score , we have to check who finish the stones first then the other person lose.  
Couple of optimization, instead of map use array, which is faster access.  
the moment dp[n] is true return , because thats the best a player can achieve, i.e. true means he has way to win, so return immediately.  


**1406. Stone Game III**  
2 player Alice and Bob play games where on each turn can choose either 1 or 2 or 3 stone.  
Winner will be person who sum is more than other.  
Alice is winner is A > B which mean A-B > 0  
Tie if A equals B which means A-B=0  
Bob wins if B > A i.e. A - B < 0.  
And both play optimally.  

Strategy is at each turn(array index) , choose either 1, 2, 3 and then recurse.  
This will be dp array dp[n][3]  
Base condition : when index is 'n', i.e. size of array tile, no move can be made so return 0.  
Pass array index in recursion based on what move is selected.
Key idea is to subtract the recursion result, this because the opponent (either Alice or Bob , play optimally).  
And then select best among the 3 moves.  
Idea is to optimally subdivide array in 2 parts where the difference is least.  

**1140. Stone Game II**  
Base condition: when all piles are taken i.e. index==n , return 0.
Memoization: At each index, m choices can be made and we have store the best of it so dp[n][m].  
Key Idea: At each index, take 1 to 2 * m piles and recurse further with new index and updated m value.  
Now since opponent will also play at its best , we have to subtract its score , so subtract the return value of recursion.  
dp[n][m], stores the max of those m moves.  

**877. Stone Game**
Two players play game and they can choose number from array from left or right end. In the end whoever sum is largest is winner.  
Array is even size and sum of array number is odd so that there is no tie.  

Here we dont bother what other person choose, we only bother to make our sum just greater than total array sum in n/2 moves.  
target = total/2 + 1  
End Condition: When n/2 moves are done , check if sum >= target return true otherwise false.  
memoization dp[l] and dp[r], at each step we can either take left index or right.  
Evaluate if not already done.  

**983. Minimum Cost For Tickets**
We have to travel on specific days and we have 3 type of pass daily, weekly, monthly.  
Find the cheapest way to travel on given days.  

Iterate each day and then on that day we have 3  choice, take the minium of it.  
Push this result to all the forward day that this minimum cost to travel on that day.  
THis will be useful when calculting in future.  

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
   
