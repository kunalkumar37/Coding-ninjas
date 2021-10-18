#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int q,n;
        cin>>n;
        int arr[n];
        int v[n];
        int p=1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            p=p*arr[i];
        }
         for(int i=0;i<n;i++)
        {
             int q=p/arr[i];
           v[i]=q;
        }
	
       for(int i=0;i<n;i++)
       {
           cout<<v[i]<<" ";
       }
        cout<<endl;
    }
}