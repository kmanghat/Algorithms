#include <bits/stdc++.h>

using namespace std;

//Function that returns longest suffix that matches prefix for each stage of the string
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string s;
    while(cin >> s && s != ".")
    {
        vector <int> pi = prefix_function(s);
        int len = s.size();
        int last = pi[pi.size()-1];
        cout << len/(len - last)<<"\n";
    }
	//to print period just do len - last
    return 0;
}


