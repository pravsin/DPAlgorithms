#include<bits/stdc++.h>
using namespace std;

long long MaxProfitCuttingRod(long long length,vector<int> prices){

    vector<int> val(length+1);
    val[0]=0;
    for (int i = 1; i <= length; ++i) {
        int maxv= INT_MIN;
        for (int j = 0; j < i; ++j) {
            maxv= max(maxv,prices[j]+val[i-j-1]);
        }
        val[i]= maxv;
    }
    return val[length];
}