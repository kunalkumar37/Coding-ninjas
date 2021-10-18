#include<bits/stdc++.h>
using namespace std;
#define ll long long

int maxSubarraySum(int arr[], int n)
{
  
    
    int sum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum<0)
        {
            sum=0;
            maxsum=max(maxsum,sum);
        }
        else{
            sum=sum+arr[i];
            maxsum=max(maxsum,sum);
        }
    }
    return maxsum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
   cout<< maxSubarraySum(arr,n)<<endl;
    }
}