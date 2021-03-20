**Problem** : This is a LeetCode problem https://leetcode.com/problems/edit-distance/  
where we are 2 string _word1_ and _word2_ and we have make them equal.  
There are 3 operation.  
Insert a character  
Delete a character  
Replace a character  

We will use DP to solve this problem in multiple ways.  
Background: 
We will always match on word2, i will index word1 and j will index word2.  
At a given index **i** in word1 and **j** in word2 in both string , if the characters doesn't match, we have 3 option.  
- **Replace** the characters i.e. make characters at index i in word1 and j in word2 equal, that means all good and lets goto [i+1, j+1].  
- **Insert**, this means we are trying to make i,j equal by insertint a matching character before position 'j', so now i match with new inserted char ,   
              but j is still pending so we have to solve [i+1, j]  
- **Deleting** , this mean whatever is at j we are deleting, so for j we are moving ahead but i still at its position,  so we have to solve [i, j+1]  
More formally  
f(i, j) = 1 + min { f(i+1, j+1) , f(i+1, j), f(i, j+1) }  
And we have to take minimum of these.  
If characters match we have to solve [i+1, j+1]  

**Approach 1**  
So the code for this recursive solution would be  
Base Case:  
- if i reached till the end , in that case we have to see how many characters still left in word2 and return that.  
- similary we do for j if it reached till the end.  

Memoization: Use the index i and j.  
Time Complexity: O(M*N)
Space Complexity: O(M*N) plus recursion stack which will also be same.
```
int dp[505][505];
class Solution {
    string s;
    string t;
    int solve(int i, int j)
    {
        // If we have exhausted the first string
        // We have to take number of chars left in second string
        // which will be t.size()-current_index_t
        // Same logic goes if we have exhausted second string
        if(i==s.size())
            return t.size()-j;
        if(j==t.size())
            return s.size()-i;
        // Check if we have already evaluated?
        int& ret = dp[i][j];
        if(ret !=-1)
            return ret;
        ret =0;
        // Mismatch
        if(s[i]!=t[j])
        {
            // If we replace that means i,j now match lets go to next
            int rep = 1 + solve(i+1, j+1);
            // if delete that means , we go to next j, i remain same.
            int del = 1 + solve(i, j+1);
            // if insert same char , that mean i now matches 
            // but we dont know abt j , so keep j same
            int ins = 1 + solve(i+1, j);
            // Take minimum of all 3 operation
            ret = min({rep, del, ins});
        }
        else
            // i and j match, so lets goto next 
            ret = solve(i+1, j+1);
        return ret;
    }
public:
    int minDistance(string word1, string word2) {
        t = word1;
        s = word2;
        memset(&dp, -1, sizeof dp);
        return solve(0, 0);
    }
};
```
**Approach 2**  
Lets convert this memoization based recursive approach to tabulation based iterative approach.  
f(i, j) = 1 + min { f(i+1, j+1) , f(i+1, j), f(i, j+1) }  
**Step 1**  
Table constrction: create a dp table of size dp[1+m][1+n].  
Extra 1 size to handle case of string completely exhaausted.  
Base case value to initialized in table, remember in recursive solution whenever i==m we return word2.size()-j and vice versa.  
So here in tabulation approach when i==m-> dp[i][j] = word2.size() -j and when j==n -> dp[i][j] = word1.size()-i  


**Step 2**   
How to start the loops:  Notice that our recursive function is dependent on future values, hence we cant start from i=0 or j=0  
we have to start backward, when working backward future value would have been already calculated.  

```

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Iterative version of recursive approach
        // Since recursive approach rely on future value
        // we should start backward i.e. i=m j=n
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(1+m, vector<int>(1+n, 0));
        for(int i = m ; i >=0; --i)
        {
            for(int j = n ; j >=0; --j)
            {
                if(i==m) // that means word1 is exhausted
                    dp[i][j] = n - j;
                else if(j==n)
                    dp[i][j] = m - i;
                else if(word1[i]!=word2[j])
                {
                    dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                }
                else
                    dp[i][j] = dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
```
**Approach 3**  
Generally we are more familiar with starting the loop with 0 to n.   
This problem can be solve using this way as well, only the base case change i.e. when i=0 , that mean we are left with entire j length of word2 so dp[i][j]= j;  
Similar when j==0 , dp[i][j]=i  
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(1+m, vector<int>(1+n, 0));
        for(int i=0; i <= m; ++i)
        {
            for(int j=0; j<=n; ++j)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
        return dp[m][n];
    }
};
```
**Space Optimized DP**  
Above tabluation based DP approach consume space of O( M* N ), we can further reduce this to 1-D DP. 
Notice that as per DP recursive statement we are only dependent on 1-previous or 1-future row to compute the current row.  
One easy way is to maintain 2 row, one which we will fill in the value of current row and 1 row which has values from previous row operation and then alternate between this row. There is even a smart way where 2nd row itself is also not required, lets discuss that.  
