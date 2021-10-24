// given a text txt[0...n-1] and a pattern pat[0...m-1] write a fucntion to search and prints all occurences of pat[] in txt[]

// pattern searching is an important problem in jcomputer science when we do search for a string in notepad /word file or browser of data base pattern searching algorithms are used to show the search results

// by using naive approach we get worst time complexity jof O(m(n-m+1)) and the time complexity of kmp algorithm is O(n)


// the kmp matching algorithm uses degenrating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to O(n)

// The basic idea is whenver we detect a mismatch (after some matches) we already know some of the kcharacters in the text of the next window we take advantage of this informatino  to avoid matchhing the characters that we know will anyway match

// need of preprocessing 
// an important question arises from the above explanation
// how to know how many characters to be skipped to know this we pre process pattern and prepare an integer array lps[] that tells us the count of characters to be skipped


// preprocessing overview
// kmp algorithm preprocesses pat[ ] and constructs an auxillary lps[] of size m which is used to skip characters while matching

// we can name pi or lps means longest prefix 
// Examples of lps[] construction:
// For the pattern “AAAA”, 
// lps[] is [0, 1, 2, 3]

// For the pattern “ABCDE”, 
// lps[] is [0, 0, 0, 0, 0]

// For the pattern “AABAACAABAA”, 
// lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

// For the pattern “AAACAAAAAC”, 
// lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 

// For the pattern “AAABAAA”, 
// lps[] is [0, 1, 2, 0, 1, 2, 3]


// in naive algorithm where we slide the pattern by one and compare all characters all tthe characters at each shift we use value from lpa[] to decide the next characters to be mached 


// how to use lps to decide next positions 
// we start comparison of pat[j] with j=0  with characters of current window of text

// we keep matching characters txt[i] and pat[i] and keep incrementing i andd j while pat[j] and txt[i] keep matching
// txt[] = "AAAAABAAABA" 
// pat[] = "AAAA"
// lps[] = {0, 1, 2, 3} 

// i = 0, j = 0
// txt[] = "AAAAABAAABA" 
// pat[] = "AAAA"
// txt[i] and pat[j] match, do i++, j++

// i = 1, j = 1
// txt[] = "AAAAABAAABA" 
// pat[] = "AAAA"
// txt[i] and pat[j] match, do i++, j++

// i = 2, j = 2
// txt[] = "AAAAABAAABA" 
// pat[] = "AAAA"
// pat[i] and pat[j] match, do i++, j++

// i = 3, j = 3
// txt[] = "AAAAABAAABA" 
// pat[] = "AAAA"
// txt[i] and pat[j] match, do i++, j++

// i = 4, j = 4
// Since j == M, print pattern found and reset j,
// j = lps[j-1] = lps[3] = 3

// Here unlike Naive algorithm, we do not match first three 
// characters of this window. Value of lps[j-1] (in above 
// step) gave us index of next character to match.
// i = 4, j = 3
// txt[] = "AAAAABAAABA" 
// pat[] =  "AAAA"
// txt[i] and pat[j] match, do i++, j++

// i = 5, j = 4
// Since j == M, print pattern found and reset j,
// j = lps[j-1] = lps[3] = 3

// Again unlike Naive algorithm, we do not match first three 
// characters of this window. Value of lps[j-1] (in above 
// step) gave us index of next character to match.
// i = 5, j = 3
// txt[] = "AAAAABAAABA" 
// pat[] =   "AAAA"
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[2] = 2

// i = 5, j = 2
// txt[] = "AAAAABAAABA" 
// pat[] =    "AAAA"
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[1] = 1 

// i = 5, j = 1
// txt[] = "AAAAABAAABA" 
// pat[] =     "AAAA"
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[0] = 0

// i = 5, j = 0
// txt[] = "AAAAABAAABA" 
// pat[] =      "AAAA"
// txt[i] and pat[j] do NOT match and j is 0, we do i++.

// i = 6, j = 0
// txt[] = "AAAAABAAABA" 
// pat[] =       "AAAA"
// txt[i] and pat[j] match, do i++ and j++

// i = 7, j = 1
// txt[] = "AAAAABAAABA" 
// pat[] =       "AAAA"
// txt[i] and pat[j] match, do i++ and j++

// We continue this way...
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
}

void kmpsearch(char *pat,char *txt)
{
    int m=strlen(pat);
    int N=strlen(txt);

    //create lps[] that will hold the longest prefix suffix values for pattern

    int lps[m];
    //preprocess the pattern calcualtes lps[] array
    computelpsarray(pat,m,lps);
    int i=0;
    int j=0;
    while(i<N)
    {
        if(pat[j]==txt[j])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            cout<<"found pattern at index"<<i-j;
            j=lps[j-1];
        }

        //mismatches after j matches
        else if(i<N and pat[j]!=txt[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }  
            else{
                i=i+1;
            }
        }
    }
}
int main()
{
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    kmpsearch(pat,txt);
    return 0;
}
