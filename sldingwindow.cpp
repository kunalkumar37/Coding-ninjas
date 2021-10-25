//given an array of integers find the number of subarrays whose sum is equal to  a target .

#include<bits/stdc++.h>
using namespace std;

bool subarray(int *arr,int target)
{
    int currsum=arr[0];
    int p;
    int start=0,i=1;
    if(currsum==target)
        {
            p=i-1;
            cout<<"subarray just found";
            return true;
        }
    else{
    while(i<=sizeof(arr))
    {
        if(currsum>target)
        {
            currsum=currsum-arr[start];
            start+=1;

        }
        if(currsum==target)
        {
            p=i-1;
            cout<<"subarray just found";
            return true;
        }
        
        currsum=currsum+arr[i];
        
        i++;
        
    
    }
    return false;
    }
    
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int target=9;
    if(subarray(arr,target))
    {
        cout<<"yghoegon"<<endl;
    }
    else{
        cout<<"gwwww"<<endl;
    }
}