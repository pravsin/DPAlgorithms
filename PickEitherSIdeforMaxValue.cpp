#include<bits/stdc++.h>

using namespace std;

long long PickMaxValue(vector<int> values) {
    long n = values.size();
    long long dp[n][n], x, y, z;

    for (int i = 0; i < n; ++i) {
        for (int j = 0, k = i; k < n; ++k, ++j) {
            x = (j + 2 <= k) ? dp[j + 2][k] : 0;
            y = (j + 1 <= k - 1) ? dp[j + 1][k - 1] : 0;
            z = (j <= k - 2) ? dp[j][k - 2] : 0;
            dp[j][k] = max(values[j] + min(x, y), values[k] + min(y, z));
        }
    }
    return dp[0][n-1];
};