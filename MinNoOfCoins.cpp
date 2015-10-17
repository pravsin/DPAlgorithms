#include<bits/stdc++.h>
using namespace std;

long long minNoOfCoins(vector<int> coins, long long sum){
    vector<int> minCoins(sum+1,INT_MAX-100);
    vector<int> coinsDen(sum+1,-1);
    minCoins[0]=0;
    coinsDen[0]=0;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if(coins[j] <=i && minCoins[i-coins[j]]+1>minCoins[i]){
                minCoins[i]= minCoins[i-coins[j]]+1;
                coinsDen[i]= coins[j];
            }
        } 
    }
    int s = sum;
    while(s){
        cout<<coinsDen[s]<<" ";
        s=s- coinsDen[s];
    }
    return minCoins[sum];
}