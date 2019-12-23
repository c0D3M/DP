#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
int dfs(int index)
{
	dist[index] = 0;
	for (int i = 0; i< adj[index].size(); i++)
	{
		int t =0;
		if(!visited[adj[index][i]])
		{
			t  = 1;
			t += dfs(adj[index][i]);
		}
		else
			t = dist[adj[index][i]]+1; //+1 is done because we are not going in depth of already explored node
		dist[index] = max(dist[index], t);
	}
	visited[index] = true;
	return dist[index];
}
int main(int argc, char*argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N>> M;
	adj.reserve(N);
	for (int i=0; i<M;i++)
	{
		int x, y;
		cin >> x>>y;
		adj[x-1].push_back(y-1);
	}
	
	visited.assign(N, false);
	dist.assign(N, 0);
	for (int i =0 ; i< N; i++)
	{
		if(!visited[i])
			dfs(i);
	}
	sort(dist.begin(), dist.end(), greater<int>());
	cout << dist[0];
}