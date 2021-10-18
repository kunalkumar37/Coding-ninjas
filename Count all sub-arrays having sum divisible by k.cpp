#include<bits/stdc++.h>
using namespace std;
#define ll long
ll a[10000005],pre[1000005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            
        }
        unordered_map<int,int> map1;
        map1[0]++;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            int remainder=sum%m;
            if(remainder<0){
                remainder+=m;
			}
            if(map1.count(remainder)>0)
            {
                count+=map1[remainder];
            }
            map1[remainder]++;
        }
        cout<<count<<endl;
	}
}