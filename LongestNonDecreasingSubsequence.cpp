#include<bits/stdc++.h>

using namespace std;

//O(n^2) solution
long LongestNonDecreasingSubsequence1(vector<int> arr){
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
    int t = maxVal, newt = maxVal;
    stack<int> lis;
    do {
        t = newt;
        lis.push(arr[t]);
        newt = longest[t];
    } while (t != newt);
    while (!lis.empty()) {
        cout << lis.top() << " ";
        lis.pop();
    }
    return 0;
}
