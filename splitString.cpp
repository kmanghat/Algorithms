#include <bits/stdc++.h>

using namespace std;

void split(vector<string>& ans, string& s) 
{
    ans.pb("");
    for(auto i : s) 
    {
        if(i == ' ')
        {
            ans.pb("");
        }
        else 
        {
            ans.back().pb(i);
        }
    }
}

int main()
{
	return 0;
}
