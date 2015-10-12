#include<bits/stdc++.h>

using namespace std;

long knapsack(vector<int> itemswt, vector<int> itemvalue, long capacity) {
    vector<int> row(capacity + 1);
    vector<vector<int>> dp(itemswt.size()+1, row);

    for (int i = 0; i <= itemswt.size(); ++i) {
        for (int j = 0; j <=capacity ; ++j) {
            if(i==0||j==0) {
                dp[i][j] = 0;
                continue;
            }
            if(j- itemswt[i-1] >=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-itemswt[i-1]]+itemvalue[i-1]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[itemswt.size()][capacity];
}