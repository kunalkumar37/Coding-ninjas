#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int maximumsubarray(vector<int>b,int n)
{
    int sum=0;
    int maximumsum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+b[i];
        if(sum<0)
        {
            sum=0;
            maximumsum=max(maximumsum,sum);
        }
        else{
           // sum=sum+b[i];
            maximumsum=max(maximumsum,sum);
        }

    }
    return maximumsum;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];

        }
vector<int> b(n*k+1);
while(k--)
{
    for(int i=0;i<n;i++)
    {
        b.push_back(arr[i]);
    }

}
int h=b.size();
cout<<maximumsubarray(b,h);


    }
}
