#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MOVES 16 // Total 16 possible moves for KingsKnight
#define MAX_N 105
long long dp[MAX_N][MAX_N][MAX_N];
int moves[2][16] = { 
    {+1, +1, +1, -1, -1, -1, +0, +0, +2, +2, -2, -2, +1, -1, -1, +1},
    {+0, -1, +1, +0, +1, -1, -1, +1, +1, -1, -1, +1, +2, -2, +2, -2}
};
class ChessMetric {
	int n;
	int maxMoves;
	vector<int> target;
	
    public:
	long long howMany(int size, vector <int> start, vector <int> end, int nomoves) {
		memset(dp, 0, sizeof(dp));
		dp[start[0]][start[1]][0] = 1; // Base case : # of way to reach start in 0 moves is 1, since we are starting there.
		for(int i = 1; i <= nomoves; ++i)
			for (int x= 0; x < size; ++x)
				for (int y = 0; y < size; ++y)
					for (int j = 0; j < MOVES; ++j)
					{
						int n_x = x + moves[0][j];
						int n_y = y + moves[1][j];
						if(!(n_x>=0 and n_x<size and n_y>=0 and n_y<size))
							continue;
						dp[n_x][n_y][i] += dp[x][y][i-1];// # ways to reach (n_x, n_y) in i moves , acculate with i-1 moves of previous co-ordinate;
					}
		return dp[end[0]][end[1]][nomoves];
    }
};int main(int argc, char*argv[])
{
	class ChessMetric a;
	//long long ret = a.howMany(3, {0, 0}, {1, 0}, 1); //1
	//long long ret = a.howMany(3, {0, 0}, {1, 2}, 1); //1
	//long long ret = a.howMany(3, {0, 0}, {2, 2}, 1); //0
	//long long ret = a.howMany(3, {0, 0}, {0, 0}, 2); //5
	long long ret = a.howMany(100, {0, 0}, {0, 99}, 50); //1
	cout <<ret;
	return 0;
}