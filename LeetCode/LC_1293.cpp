#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef struct
{
    bool visited; // whether this cell is viisted or not.
    bool found;   // this will be set true if we found a path to destination via this cell.
    int steps;
    int obs;
}N;
class Solution {
    vector<vector<int>>G;
    vector<vector<N>> dp;
    int m, n, K;
public:
    
    bool solve(int r, int c, int o, int s)
    {
        if(r<1 || r> m || c<1|| c>n || o >K)
            return false;
	int x = G[r-1][c-1] ? 1 : 0;
        // If we already found a cheaper solution and current steps is greater than that
	// their is no use of exploring that node deeper as we only get worser solution than what we have.
	if(dp[m][n].visited && s > dp[m][n].steps)
            return false;
	
	 // Under certain scenario we will revisit an already visited node.
        if(dp[r][c].visited)
        {
	    // if we reached begining ; return 
	    if(r==c && r==1)
		return false;
	    // If we found a cheaper path 
            // or we found an exact same path but with smaller obstacle
            if ( ( s < dp[r][c].steps) || (s==dp[r][c].steps && !dp[r][c].found && o < dp[r][c].obs))
            {
                dp[r][c].obs = o;
                dp[r][c].steps = s;
                dp[r][c].found = solve(r, c+1, o+x, s+1) | solve(r+1, c, o+x, s+1) | solve(r, c-1, o+x, s+1) | solve(r-1, c, o+x, s+1) ;
            }
	    // If we got to a costlier path and obstacle are smaller that exisiting and their hasnt been any solution yet.
	    // because their is a possibility of finding a longer path with few obstacle to the destination.
            else if(s > dp[r][c].steps && o < dp[r][c].obs && !dp[r][c].found)
            {
                dp[r][c].obs = o;
                dp[r][c].steps = s;
                dp[r][c].found = solve(r, c+1, o+x, s+1) | solve(r+1, c, o+x, s+1) | solve(r, c-1, o+x, s+1) | solve(r-1, c, o+x, s+1) ;    
            }
        }
        else
        {
	   // Not yet visited, so traverse right, down, left, up.
            dp[r][c].visited = true;
            dp[r][c].obs = o;
            dp[r][c].steps = s;
            dp[r][c].found = solve(r, c+1, o+x, s+1) | solve(r+1, c, o+x, s+1) | solve(r, c-1, o+x, s+1) | solve(r-1, c, o+x, s+1) ;
        }
	    
	// Reached destination
        if(r==m && c==n)
	    return true;
        else
            return dp[r][c].found;
    
    }
    int shortestPath(vector<vector<int>> grid, int k) {
        G = grid;
        m = grid.size();
        n = grid[0].size();
        K = k;
        
        dp.resize(m+1);
        for (int i = 0 ; i < m+1; ++i)
            dp[i].resize(n+1);
        
        dp[0][0].visited = true;
        dp[0][0].steps = 0;
        dp[0][0].obs = 0;
        
        solve(1, 2, 0, 1);
        solve(2, 1, 0, 1);
        solve(1, 0, 0, 1);
        solve(0, 1, 0, 1);
        
        if((m==n)&& m==1)
            return 0;
        return dp[m][n].visited ? dp[m][n].steps : -1;  
    }
};
int main(int argc, char*argv[])
{
	class Solution s;
	cout << s.shortestPath(
	{{0,1,1,1,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,0,1},{0,0,0,0,0,1,1,0,0,1,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1},{0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,1,1,0,0,0,1,1},{0,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,1,1},{1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,1,1,1,0,0,1},{1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1},{0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1},{0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,1,0},{0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0},{0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},{1,0,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1},{0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1},{0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1},{1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,0,1},{1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1},{1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1},{0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1},{1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1},{0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0},{0,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1},{0,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0},{1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1},{0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,1,0}}
,617);
	
	//{{0,1,0,0,0,1,0,0},{0,1,0,1,0,1,0,1},{0,0,0,1,0,0,1,0}}, 1)<<"\n";
}
/*
Test Cases:
{{0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0}}
1
{{0,1,0,0,0,1,0,0},{0,1,0,1,0,1,0,1},{0,0,0,1,0,0,1,0}}
1
{{0,0,1,0,0,0,0,1,0,1,1,0,0,1,1},{0,0,0,1,1,0,0,1,1,0,1,0,0,0,1},{1,1,0,0,0,0,0,1,0,1,0,0,1,0,0},{1,0,1,1,1,1,0,0,1,1,0,1,0,0,1},{1,0,0,0,1,1,0,1,1,0,0,1,1,1,1},{0,0,0,1,1,1,0,1,1,0,0,1,1,1,1},{0,0,0,1,0,1,0,0,0,0,1,1,0,1,1},{1,0,0,1,1,1,1,1,1,0,0,0,1,1,0},{0,0,1,0,0,1,1,1,1,1,0,1,0,0,0},{0,0,0,1,1,0,0,1,1,1,1,1,1,0,0},{0,0,0,0,1,1,1,0,0,1,1,1,0,1,0}}
27
{{0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1},{1,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0},{0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0},{1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},{0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,0},{1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1},{1,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0}}
283
{{0,1,1,1,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,0,1},{0,0,0,0,0,1,1,0,0,1,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1},{0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,1,1,0,0,0,1,1},{0,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,1,1},{1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,1,1,1,0,0,1},{1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1},{0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1},{0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,1,0},{0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0},{0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},{1,0,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1},{0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1},{0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1},{1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,0,1},{1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1},{1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1},{0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1},{1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1},{0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0},{0,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1},{0,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0},{1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1},{0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,1,0}}
617
{{0}}
1
*/
