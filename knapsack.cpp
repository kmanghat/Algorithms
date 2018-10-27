//Dynamic Programming solution using a table
#include <bits/stdc++.h>

using namespace std;

//To find answer from table
void findIdx(vector<vector<int>>& v, int i, int j, vector<int>& result, vector<pair<int, int>>& items) 
{
    if(v[i][j] == 0) 
    {
        return;
    }

    if(v[i-1][j] == v[i][j]) 
    {
        findIdx(v, i-1, j, result, items);
    }
    else 
    {
        findIdx(v, i-1, j-items[i].second, result, items);
        result.push_back(i-1);
    }
}

int main()
{
    double c;
    int items;
    
    //C is capacity and n is possible items
    while(cin >> c)
    {
        cin >> items;
        //1/0 knapsack problem
        int capacity = floor(c);
        
        //Table to store possible combinations
        vector<vector<int>> table;
        table.resize(items+1,vector<int>(capacity+1,0));
        
        //Input all items <value,weight>
        vector <pair<int,int>> obj;
        obj.resize(items+1);
        obj[0].first = 0;
        obj[0].second = 0;
        for (int i = 1; i <= items; i++)
        {
            cin >> obj[i].first >> obj[i].second;
        }
        
        //Algorithim to construct table
        //Table row is item + 1 and col is capacity + 1
        for(int i = 1; i <= items; i++)
        {
            for(int j = 1; j <= capacity; j++)
            {
                //If capacity is less than current object assign the previous rows value to current row
                //same col
                if(j < obj[i].second)
                {
                    table[i][j] = table[i - 1][j];
                }
                //If not use the max of these two values
                else
                {
                    table[i][j] = max(table[i-1][j-obj[i].second]+obj[i].first, table[i-1][j]);
                }
            }
        }
        
        
        vector<int> result;
        findIdx(table,items,capacity,result,obj);
        cout << result.size() <<endl;
        for(int i = 0;  i < result.size() ; i++)
        {
            cout << result[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}
