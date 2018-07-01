#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
int p[MAX_N];

int find(int x)
{
	//return if x is its own parent
	if(p[x] < 0)
		return x;
	
	p[x] = find(p[x]);
	return p[x];
}

void unite(int x, int y)
{
	//they belong to same set
	if((x = find(x)) == (y = find(y)))
		return;
	
	//x is the deeper set(contains more items)
	if(p[y] < p[x])
		swap(x,y);
	
	p[x] += p[y];
	p[y] = x;
}

int main()
{
	for(int i = 0; i < 5; i++)
	{
		p[i] = -1;
	}
	
	unite(1,2);
	unite(1,3);
	
	for(int i = 0; i < 5; i++)
	{
		cout<<p[i]<<endl;
	}
	
	return 0;
}
	
