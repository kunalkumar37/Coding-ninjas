#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll count=0;
        while(n!=m)
        {
            n=n+2;
            count+=2;
            if(n>m)
            {
                n=n-1;
                count+=1;
            }


        }
        cout<<count<<endl;

    }
    return 0;
}