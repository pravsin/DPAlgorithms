#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int board[32][32], buffer[32][32];
void rotate() {
    int n =10; // size of matrix (its a square matrix)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            buffer[n - j - 1][i] = board[i][j];
    memcpy(board, buffer, sizeof(board));
}
