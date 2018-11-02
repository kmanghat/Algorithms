#include <bits/stdc++.h>

using namespace std;


int sum(int BIT[], int idx)
{
    int sum = 0;
    
    for(int i = idx ; i > 0; i -= i&-i)
    {
        sum += BIT[i];
    }
    
    return sum;
}
void update(int BIT[], int val,int idx)
{
    //find parent to be inserted and add val to it (1 or -1)
    for(int i = idx ; i < 200002; i += i&-i)
    {
        BIT[i] += val;
    }
}
        
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int cases;
    cin>>cases;
    
    while(cases != 0)
    {
        int pos[100001];
        int BIT[200002];
        
        int m, r;
        
        cin>>m>>r;
        
        //initialize BIT to 0's
        for(int i = 0; i < 200002; i++)
            BIT[i] = 0;
            
        
        
        for(int i = 1; i <= m; i++)
        {
            update(BIT,1,i);
            //so 5,4,3,2,1 for 1 2 3 4 5
            pos[i] = m - i + 1;
            
        }
        
        int q;
        int loc;
        vector<int> ans;
        for(int i = m + 1 ; i <= m + r; i++)
        {
            //movie number
            cin>>q;
            
            //location of movie
            loc = pos[q];
            
            //sum returns the sum of all elements after loc hence subtracting
            // gives elements before
            ans.push_back(m - sum(BIT,loc));
            
            //simulate removing from a stack
            update(BIT,-1,loc);
        
            //simulate putting back on top
            update(BIT,1,i);
    
            //change spot for next itr
            pos[q] = i;
        }
                
        for(int i = 0 ; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
                
        
        cases--;
        
    }
    return 0;
}

