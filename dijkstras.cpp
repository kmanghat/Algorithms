//Dijkstras
#include <bits/stdc++.h>

using namespace std;

//edge of graph
struct edge
{
	int u,v;
	int weight;
	
	edge(int _u,int _v, int _w)
	{
		u = _u;
		v = _v;
		weight = _w;
	}
};

//store distance and edges
vector<int> dist(1000001,20000000);
vector<edge> adj[1000000];

//Dijkstras
void dijkstras(int start)
{
	//Mark start node as zero
	dist[start] = 0;
	//priority queue in ascending order of weight
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	//push first element into pq
	pq.push(make_pair(dist[start], start));
	
	//loop till empty
	while(!pq.empty())
	{
		//u is node and d is distance of that node from s
		int u = pq.top().second;
		int d = pq.top().first;
		
		//remove edge
		pq.pop();
		
		//if distance is greater current distance then ignore 
		if(d > dist[u])
			continue;
		
		//loop through connected edges of u
		for(int i = 0; i < adj[u].size(); i++)
		{
			//v is the node u is connceted to w is its weight
			int v = adj[u][i].v;
			int w = adj[u][i].weight;
			
			//if w + curr w is less that in node v then store it 
			if(w + dist[u] < dist[v])
			{
				dist[v] = w + dist[u];
				pq.push(make_pair(dist[v],v));
			}
		}
	}
}	

int main()
{
	int n, m,q,s;
	
	while(cin>>n>>m>>q>>s && (n!=0 || m != 0 || q!= 0 || s!= 0))
	{
		for(int i = 0; i < 1000001; i++)
		{
			dist[i] = 20000000;
		}
		
		for(int i = 0; i < m; i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
		
			adj[u].push_back(edge(u,v,w));
		}
		
		dijkstras(s);
		
		int query;
		for(int i = 0; i < q; i++)
		{
			cin>>query;
			
			if(dist[query] >= 20000000)
				cout<<"Impossible"<<endl;
			else
				cout<<dist[query]<<endl;
		}
		
		for(int i = 0; i < 1000000; i++)
			adj[i].clear();
	}

	return 0;
}
