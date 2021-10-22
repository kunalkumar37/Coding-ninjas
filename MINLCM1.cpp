#include<bits/stdc++.h>
#define ll long long
using namespace std;
int findlcm(int a,int b)
{
    int lcm;
    if(a>b)
    {
        lcm=a;

    }
    else{
        lcm=b;
    }
    while (1)
    {
        if(lcm%a==0  and lcm%b==0)
        {
            return lcm;
            break;
        }
        lcm++;
    }
    
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;

        
        
        cout<<2*x<<" "<<x*k*(x*k-1)<<endl;
    }
    return 0;
}