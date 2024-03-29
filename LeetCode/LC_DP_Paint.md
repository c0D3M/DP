[**256. Paint House**](https://leetcode.com/problems/paint-house/)  
Solving using DFS+masking and also doing memoization is straightforward.  
**Top Down DP DFS+ Memoization**:
```
class Solution {
    int n;
    vector<vector<int>> dp;
    int color[3] = {1, 2, 3};
    int solve(int index, int mask, vector<vector<int>>& costs){
        if(index==n)
            return 0;
        int& ret = dp[index][mask];
        if(ret!=-1)
            return ret;
        ret = INT_MAX;
        for(int c =0; c< 3; ++c){
            if(color[c]!=mask){
                ret = min(ret, costs[index][c]+solve(index+1, color[c], costs));
            }
        }
        return ret;
    }
public:
    int minCost(vector<vector<int>>& costs) {
        this->n = costs.size();
        dp.resize(n, vector<int>(4, -1));
        return solve(0, 0, costs);
    }
};
```
When we enter recursive call for a house to be painted , we check if this house with mask color has been already evaluated earlier ? if yes return.  

**Bottom-up DP**:
Lets see how this can be solved bottom-up DP iteratively.  
As each house , if I decide to paint by a particular color for example RED that means previous house has to be painted by either BLUE or GREEN, so take minimum of them
our dp state would be dp[i] = cost[i][RED] + min(dp[i-1][GREEN] , dp[i-1][BLUE]  
and like that for other 3 color.  
in the end return minimum number in the last row (last house)

```
class Solution {
     enum Color{
         RED =0,
         GREEN,
         BLUE
     };
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(1+n, vector<int>(3));
        for(int i = 1; i<=n; ++i){
            // Red paint
            dp[i][RED] = costs[i-1][RED] + min(dp[i-1][GREEN], dp[i-1][BLUE]);
            dp[i][GREEN] = costs[i-1][GREEN] + min(dp[i-1][RED], dp[i-1][BLUE]);
            dp[i][BLUE] = costs[i-1][BLUE] + min(dp[i-1][GREEN], dp[i-1][RED]);
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};
```

**Improvement 3**:
Lets see how can we further reduce Space complexity which is O(n) above to O(1). 
As can be seen we are dependent only only previous row, we dont need all the other previous row, and this previous row has just 3 values, so why not store in 3 variables.
```
class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int r =0, g =0, b =0;
        for(int i = 0; i<n; ++i){
            int o_r =r, o_g =g, o_b =b;
            r = costs[i][0] + min(o_g, o_b);
            g = costs[i][1] + min(o_r, o_b);
            b = costs[i][2] + min(o_g, o_r);
            
        }
        return min(min(r, g), b);
    }
};
```
Time Complexity is all the above 3 cases is O(n), however the last one beats 99% on both space and time.  

[**265. Paint House II (Hard)**](https://leetcode.com/problems/paint-house-ii/)  
Instead of 3 colors now we have k colors, same like above approach but now we have to run a loop and time complexity would be O(n * k^2)
```
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k,0));
        for(int i =0; i < n ; ++i){
            // Fill dp[i&1] with INT_MAX
            fill(dp[i&1].begin(), dp[i&1].end(), INT_MAX);
            for(int j = 0 ; j < k; ++j)
                for(int l=0; l < k; ++l)
                    if(j!=l)
                        dp[i&1][j] = min(dp[i&1][j], costs[i][j] +  dp[!(i&1)][l]);
        }
        return *min_element(dp[!(n&1)].begin(), dp[!(n&1)].end());
    }
};
```
Follow up is how to get O(n* k), key idead is while painting with kth colors, you want to compare eveything in previous row except kth color and you want minimum from those k-1 value.  
Lets see this with an example.  
Suppose you have first row house cost of k paint as follows 1st paint cost as 1 , 2nd paint cost 2 ....  
Row 1:     1 2 3 4 5  
Row 2:     ^ at this point you have decided to paint with 1st color, so Row 1 you cant take 1, you have take min(2,3,4, 5)  
Essentially you need to track minimum value and next minimum of previous row, so that in case of clash of column index you can use next minimum and thats how we can reduce  time complexity to O(n* k)
I am maintaining both cost and index for cheapest and next_cheapest in pair variable.

```
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k,0));
        pair<int, int> low(0, 0); // val, index
        pair<int, int> next_low(0, 1); // val, index
        for(int i =0; i < n ; ++i){
            // Fill dp[i&1] with INT_MAX
            fill(dp[i&1].begin(), dp[i&1].end(), 10000);
            pair<int, int> new_low(10000, 0);
            pair<int, int> new_next_low(10000, 1);
            for(int j = 0 ; j < k; ++j)
            {
                if(j==low.second){
                    dp[i&1][j] = min(dp[i&1][j], costs[i][j] +  next_low.first);
                }
                else
                {
                    dp[i&1][j] = min(dp[i&1][j], costs[i][j] +  low.first);
                }
                if(dp[i&1][j] < new_low.first )
                {
                    new_next_low = new_low;
                    new_low.first = dp[i&1][j];
                    new_low.second = j;
                }
                
                else if( dp[i&1][j] < new_next_low.first ){
                    new_next_low.first = dp[i&1][j];
                    new_next_low.second = j;
                }
                
            }
            low = new_low;
            next_low = new_next_low;
        }
        return *min_element(dp[!(n&1)].begin(), dp[!(n&1)].end());
    }
};
```



[**1473. Paint House III (Hard)**](https://leetcode.com/problems/paint-house-iii/)  
Eaxct same as LC 256 just that an extra dimension of number of neighbourhood has been added.  
And we should have exact k neighbourhood, so if k falls less than 0 return max(this is not a valid painting sequence).  
We decrease neighbourhood if current paint is diffrent than previoys paint.  
Thats all 

```
class Solution {
    int m , n;
    vector<vector<vector<int>>> dp;
     int max =1000001;
    int solve(int index, int count, vector<int>& houses, vector<vector<int>>& cost,  int p ){
        if(count < 0)
            return max;
        // have we reached end ?
        if(index==m){
            //do we get to target
            if(count==0)
                return 0;
            return max;
        }
        int& ret = dp[index][p][count];
        if(ret!=0)
            return ret;
        
        if(houses[index]!=0)
        {
            return ret = solve(index+1, count - (houses[index]!=p), houses, cost,  houses[index]);
        }
        ret = max;
        // Lets paint this house, there are n ways
        for(int i =1; i <= n ; ++i){            
             houses[index] = i;
            ret = min(ret, cost[index][i-1] + solve(index+1, count - (i!=p), houses, cost, i));
            houses[index] = 0;
        }
        return ret;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = m; // m houses
        this->n = n; // n colors
        dp.resize(m, vector<vector<int>>(1+n, vector<int>(2+target, 0)));
        int ans = solve(0, target, houses, cost, 0);
        return ans< max  ? ans : -1;
    }
};
```
[**276: Paint Fence Medium**](https://leetcode.com/problems/paint-fence/)  
First paint we have k choice
2nd fence : same as 1st : we have 1 choice, i.e. paint same as previous  so total = k *  1.  
2nd fence : diff as 1st: we have k-1 option: total = k * k-1  
total = same +diff = k + k * (k-1)  

For 3rd fence : same as 2nd fence , pick oldDiff (of 2nd steps) and we have just 1 choice = k* k-1  
For 3rd fence : diff as 2nd fence, we have k-1 color to choose from: and we have all the previous combonation to pick = (sum + diff) * k-1  
```
   int same = k; // 2 post painted in same color  , 1st post k option, 2nd post just 1 option
        int diff = k * (k-1); // 2 post painted in diff color, 1st post we hve k option and 2nd k-1
        for(int i =3; i <=n; ++i){
            int oldDiff = diff;
            // to post 3rd fence ina diff color that of 2nd fence we have k-1 option
            // and how many total way of 2nd fence , we get from sum of diff + same
            diff = (same + diff ) * (k-1);
            
            // Now we are saying 3rd and 2nd fence same color
            same = oldDiff;
        }
        return same + diff;
```
        
[**1411. Number of Ways to Paint N × 3 Grid Hard**](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)  

Key difference:
We are using 3 colors and here the colors cant be same as previous or upper cell, this lead us in maintaining mask both for current Row as well as previous Row.  
To represent 3 colors we need 2 bits and hence the mask is total 2 * 3 = 6 bits and whenever we set/get mask we should bitshift by  2 * column #.  
When to use dp memo : we you start first column of a new row , check prev mask i.e. dp[r][prevMask], if its available use it , since all further calculation going to be same.  



[**1931. Painting a Grid With Three Different Colors Hard**](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)  
Same as above except row & columns are interchanged and we now have 5 column so our mask can have 2 * 5 = 10 bits i.e. total 1024 combination of bits.  

