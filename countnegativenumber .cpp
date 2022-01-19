#include<bits/stdc++.h>
using namespace std;

int numofones(vector<int>row)
{
	int lo=0;
	int hi=row.size();
	while(lo<hi)
	{
		int mid=lo+(hi-lo)/2;
		if(row[mid]==1)
		{
			lo=mid+1;

		}
		else
		{
			hi=mid;
		}
	}
	return lo;
}

vector<int>kweakestrows(vector<vector<int>> &mat,int k)
{
	int rows=mat.size();
	int cols=mat[0].size();

	int score[rows];
	int j;

	for(int i=0;i<rows;i++)
	{
		j=numofones(mat[i]);
		score[i]=j*rows+i;

	}

	sort(score,score+rows);
	vector<int>ans(k);
	for(int i=0;i<k;i++)
	{
		ans[i]=score[i]%rows;
	}
return ans;


}

int main()
{
	 vector<vector<int> > arr = { {1,1,0,0,0 }, 
                              { 1,1,1,1,0 }, 
                              { 1,0,0,0,0 },
                              { 1,1,0,0,0 },
                              { 1,1,1,1,1 }}; 
 int k=3;    

vector<int>ans=kweakestrows(arr,k);
for(int i=0;i<k;i++)
{
	cout<<ans[i]<<" ";

}   
cout<<endl;
return 0;                        
}