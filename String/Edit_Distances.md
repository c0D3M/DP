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
And we have to take minimum of these.  
If characters match we have to solve [i+1, j+1]

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
