#include<bits/stdc++.h>
using namespace std;

/*
 * We are given a SUM and some coins , we have to find no of ways in which sum can be represented
 * with coins, each coin can be used unlimited times. (order of coins does not matter)
 * e.g if sum =4 and coins ={1,2,3}
 * possible combinations are {1,1,1,1},{1,1,2},{2,2} and {1,3}  so answer is 4.
 */

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

/*
 * variation of above problem  - in this every coin can be used only once.
 */
long long coinChangeMaxOneCoin(vector<int> coins, long long sum){
    long long m = coins.size();
    vector<long long> dp(sum+1,0);
    dp[0]=1;
    for (int i = 0; i < m; ++i) {
        for (int j = sum; j >= coins[i]; --j) {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[sum];
}