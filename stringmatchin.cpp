#include<bits/stdc++.h>
using namespace std;

bool ismatching(string s,string p)
{
    int n=s.length();
    int m=p.length();

    for(int i=0;i<(n-m);i++)
    {
        bool isfound=true;
        for(int j=0;j<m;j++)
        {
            if(s[i+j]!=p[j])
            {
                //return false;
                isfound=false;
                break;
            }
        }
        if(isfound==true)
        {
            return true;

        }
    }
    return false;
}

int main()
{
    string s,p;
    cin>>s>>p;
    cout<<ismatching(s,p)<<endl;
    return 0;
}