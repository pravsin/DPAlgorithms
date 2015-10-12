#include<bits/stdc++.h>

using namespace std;

int lps(string s) {
    int dp[s.size()][s.size()];
    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = 1;
    }
    for (int j = 2; j <= s.size(); ++j) {
        for (int i = 0; i <s.size()-j+1 ; ++i) {
            if(s[i] == s[i+j-1] && j ==2)
                dp[i][i+j-1]=2;
            else if(s[i]==s[i+j-1])
                dp[i][i+j-1] = 2+ dp[i+1][i+j-2];
            else
                dp[i][i+j-1] = max(dp[i][i+j-2],dp[i+1][i+j-1]);
        }
    }
    return dp[0][s.size()-1];
}