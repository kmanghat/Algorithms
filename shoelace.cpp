//Finds Area of polygon
#include <bits/stdc++.h>

using namespace std;


double shoelace(vector<pair<int,int>> points)
{
	double sum1,sum2;
	sum1 = 0; sum2 = 0;
	
	for(int i = 0; i < points.size() -1; i++)
	{
		sum1 += points[i].first * points[i + 1].second;
		sum2 += points[i].second * points[i + 1].first;
	}
	
	sum1 += points[points.size()-1].first * points[0].second;
	sum2 += points[points.size()-1].second * points[0].first;
	
	double area = sum1-sum2;
	area /= 2;
	return area;
}
	 
int main()
{

	return 0;
}
