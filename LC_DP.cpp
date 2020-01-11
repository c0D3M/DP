#include <bits/stdc++.h>
#include <algorithm>
/*
Given a matrix of direction with L, R, U, D, 
at any point you can move to the direction which is written over the cell [i, j]. 
We have to tell minimum number of modifications to reach from [0, 0] to [N - 1, M - 1] .

Example :-
R R D
L L L
U U R
Answer is 1, we can modify cell [1, 2] from L To D.
*/
using namespace std;
int N, M;
int best = 1e+5;
vector<vector<char>> tile;
vector<vector<bool>> visited;
void solve(int r, int c, char expected, int steps)
{
	if (r>N || c>M || r<1 || c<1 || visited[r][c])
		return;
	if(tile[r][c] != expected)
		++steps;

	
	if(steps > best) // We alredy found best with lesser steps, prune the recursion tree.
		return;
		
	if(r==1 && c==1) // we reached top 
	{
		best = steps;
		return;
	}	
	visited[r][c] = true;
	solve(r-1, c, 'D', steps);
	solve(r, c+1, 'L', steps);
	solve(r+1, c, 'U', steps);
	solve(r, c-1, 'R', steps);
}
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N>>M;
	tile.reserve(N+1);
	visited.reserve(N+1);
	for (int i = 1 ; i <= N; ++i)
	{
		tile[i].reserve(M);
		visited[i].reserve(M);
		for (int j = 1; j <=M; ++j)
			cin >> tile[i][j];
	}
	visited[N][M] = true;
	solve(N-1, M, 'D', 0);
	solve(N, M-1, 'R', 0);
	cout << best;
}