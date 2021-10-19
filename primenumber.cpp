#include<bits/stdc++.h>
using namespace std;

bool checkprime(int n)
{
    int count=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i ==0)
        {
            if(i*i ==n)
            {
                count+=1;
            }
            count+=2;
        }
    }
    if(count==2)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int count;

    for(int i=1;i<=n;i++)
    {
        if(checkprime(i))
        {
            count++;
        }
    }
    cout<<count<<endl;
}