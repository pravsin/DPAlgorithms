#include<bits/stdc++.h>
using namespace std;

long long coinChange(vector<int> coins, long long sum){
    long long m = coins.size();
    vector<long long> dp(sum+1,0);
    dp[0]=1;
    for (int i = 0; i < m; ++i) {
        for (int j = coins[i]; j <= sum; ++j) {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[sum];
}