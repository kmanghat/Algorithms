#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
int BIT[MAX_N];

int sum(int idx)
{
	int sum = 0;
	
	//Start from index and go till 0
	for(int i = idx; i > 0; i -= (i&-i))
	{
		sum += BIT[i];
	}
	
	return sum;
}

void update(int val, int idx)
{
	for(int i = idx; i <= MAX_N; i += (i&-i))
	{
		BIT[i] += val;
	}
}

int main()
{
	memset(BIT,0,sizeof(BIT));
	
	for(int i = 0; i < 5; i++)
	{
		update(1,i+1);
	}
	
	for(int i = 0; i <= 5; i++)
		cout<<sum(i)<<endl;
	
	cout<<endl;
	return 0;
}
