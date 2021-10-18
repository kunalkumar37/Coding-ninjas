#include<iostream>
using namespace std;
int sumofarray(int n,int *arr)
{int sum=0;
    for(int i=0;i<n;i++)
    {
        
        sum=sum+arr[i];
        
    }
    return sum;
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
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int sum1=r/n*sumofarray(n,arr)+sumofarray(r%n,arr);
            int sum2=(l-1)/n * sumofarray(n,arr)+sumofarray((l-1)%n,arr);
            
            cout<<sum1-sum2<<endl;
        }
    }
}