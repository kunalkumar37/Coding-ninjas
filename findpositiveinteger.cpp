#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> findsolution(CustomFunction &customFunction,int z)
{
	vector<vector<int>>res;
	int y=1000;
	for(int x=1;x<=1000;++x)
	{
		while(y>1 and customFunction.f(x,y)>z)
		{
			y--;
		}

		if(customFunction.f(x,y)==z)
		{
			res.push_back({x,y});
		}
	}

	return res;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
}