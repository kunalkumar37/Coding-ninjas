// Given an array A consisting of natural numbers, and a number P, find the length of the minimum length subarray whose product is >= P.
#include<bits/stdc++.h>
using namespace std;

int minsubarray(int *arr,int p)
{
    int n=arr.length();
    int i=0,j=0;
    int curp=1;
    int ans=INT_MAX;
    while(i<n)
    {
        while(j<n and curp<p)
        {
            curp=curp*arr[j];
            j++;
        }
        if(curp>=p)
        {
            ans=min(ans,j-i+1);
            curp=curp/arr[i];
            i++;
        }
    }
    return ans;
}

int main()
{

    int arr[]={1,2,3,4,5,6};
    int p=20;

    cout<<minsubarray(arr,p);

}