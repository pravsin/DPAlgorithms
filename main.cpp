#include<bits/stdc++.h>

using namespace std;
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


    cout<<"\n";
    for (int l = 0; l < n; ++l) {
        cout<<pre[l]<<" ";
    }

    return 0;
}
int main() {
    vector<int> arr{ 100, 22, 9, 33, 21, 50, 41, 60, 50,50,50 };
    LongestNonDecreasingSubsequence(arr);
    return 0;
}