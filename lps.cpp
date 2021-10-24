#include<bits/stdc++.h>
using namespace std;

void computelpsarray(char *pat,int m,int *lps)
{
    int len=0;
    lps[0]=0;
    // the loop is calcualting lps[i] for i=1 to m-1
    int i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else{
            //pat[i]!=pat[len]
            if(len!=0)
            {
                len=lps[len-1];

            }
            else{  //if(len==0)
                lps[i]=0;
                i++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<lps[i]<<endl;
    }
}

int main(){
    char pat[]="ABABCABAB";
    int m=strlen(pat);
    int lps[m];
    computelpsarray(pat,m,lps);
    return 0;
}