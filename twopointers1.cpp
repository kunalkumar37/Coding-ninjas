// Given a sorted array and a number S, find the indices of any two elements which sum up to exactly S, or report that such a pair does not exist.

#include<bits/stdc++.h>
using namespace std;
void array1(int *a,int s)
{
    int t[2]={-1,-1};
    int n=sizeof(a);
    int i=0,j=n-1;
    while(i<=j)
    {
        int cursum=a[i]+a[j];
        if(cursum==s)
        {
            t[0]=i;
            t[1]=j;
        }
        else if(cursum<s)
        {
            i++;
        }
        else{
            j++;
        }

    }
    cout<<t[0]<<" "<<t[1]<<endl;
    

}
int main()
{
    int arr[]={1,2,3,4,5,6};
    int sum=6;

    array1(arr,sum);
}