#include<bits/stdc++.h>
using namespace std;


bool isvalid(int weight[],int n,int d,int mx)
{
	int st=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+weight[i];


		if(sum>mx)
		{
			st++;
			sum=weight[i];
		}

		if(st>d)
		{
			return false;
		}
	}
	return true;
}


void shipwithindays(int weight[],int d,int n)
{
	int sum=0;


	for(int i=0;i<n;i++)
	{
		sum+=weight[i];

	}

	int s=weight[0];
	for(int i=1;i<n;i++)
	{
		s=max(s,weight[i]);
	}

	int e=sum;
	int res=-1;


	while(s<=e)
	{
		int mid=s+(e-s)/2;

		if(isvalid(weight,n,d,mid))
		{
			res=mid;
			e=mid-1;
		}

		else
		{
			s=mid+1;
		}
	}

	cout<<res;
}



int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int weight[]={9,8,10};
    int d=3;
    int n=sizeof(weight)/sizeof(weight[0]);
    shipwithindays(weight,d,n);
    
}