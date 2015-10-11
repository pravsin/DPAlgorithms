#include<bits/stdc++.h>

using namespace std;

//O(n^2) solution
long LongestNonDecreasingSubsequence(vector<int> arr){
    long n = arr.size();
    vector<int> longest(n,1),pre(n);
    for (int i = 0; i < n; ++i) {
        pre[i]=i;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(arr[j]<=arr[i]){
                if(longest[j]+1 > longest[i]) {
                    longest[i] = longest[j] + 1;
                    pre[i]=j;
                }
            }
        }
    }
    int maxVal=0;
    for (int k = 1; k < n; ++k) {
        if(longest[k]>longest[maxVal])
            maxVal = k;
    }
    cout<<"Length of longest Non Decreasing Subsequence is "<<longest[maxVal]<<"\n";
    int j ,t= maxVal;
    //Printing the subsequence in reverse order
    // use vector<int> to store the result and then reverse it and then print it if want in non-decreasing order
    do{
        j=t;
        cout<<arr[j]<<" ";
        t=pre[j];
    }while(j!=t);

    return 0;
}
