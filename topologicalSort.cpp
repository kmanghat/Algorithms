#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100000];
vector<bool> visited(1000, false);
vector<int> order;

void toposort(int u)
{
	if(visited[u])
		return;
		
	visited[u] = true;
	
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		toposort(v);
	}
	
	order.push_back(u);
}


int main()
{
	

	return 0;
}
