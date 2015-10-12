#include<bits/stdc++.h>

using namespace std;

/*
 * Python2 code
 def longest_common_substring(s1, s2):
    m = [[0] * (1 + len(s2)) for i in xrange(1 + len(s1))]
    longest, x_longest = 0, 0
    for x in xrange(1, 1 + len(s1)):
        for y in xrange(1, 1 + len(s2)):
            if s1[x - 1] == s2[y - 1]:
                m[x][y] = m[x - 1][y - 1] + 1
                if m[x][y] > longest:
                    longest = m[x][y]
                    x_longest = x
            else:
                m[x][y] = 0
    return s1[x_longest - longest: x_longest]
 */

int LongestCommonSubstring(const string &str1, const string &str2) {
    if (str1.empty() || str2.empty()) {
        return 0;
    }

    int *curr = new int[str2.size()];
    int *prev = new int[str2.size()];
    int *swap = nullptr;
    int maxSubstr = 0;

    for (int i = 0; i < str1.size(); ++i) {
        for (int j = 0; j < str2.size(); ++j) {
            if (str1[i] != str2[j]) {
                curr[j] = 0;
            }
            else {
                if (i == 0 || j == 0) {
                    curr[j] = 1;
                }
                else {
                    curr[j] = 1 + prev[j - 1];
                }
                //The next if can be replaced with:
                //maxSubstr = max(maxSubstr, curr[j]);
                //(You need algorithm.h library for using max())
                if (maxSubstr < curr[j]) {
                    maxSubstr = curr[j];
                }
            }
        }
        swap = curr;
        curr = prev;
        prev = swap;
    }
    delete[] curr;
    delete[] prev;
    return maxSubstr;
}