#include<bits/stdc++.h>

using namespace std;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))


int L[1005][1005];
int D[1005][1005];

void convert10tob(int N, int b) {
    if (N == 0)
        return;

    int x = N % b;
    N /= b;
    if (x < 0)
        N += 1;

    convert10tob(N, b);
    printf("%d", x < 0 ? x + (b * -1) : x);
    return;
}

void multiply_by_scalar(vector<int> &a, int n) {
    if (!n) {
        a.clear();
        return;
    }
    int carry = 0;
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i] * n + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    for (; carry; carry /= 10)
        a.push_back(carry % 10);
}

void print(const vector<int> &a) {
    if (a.empty()) printf("0");
    else {
        for (int i = (int) a.size() - 1; i >= 0; --i)
            printf("%d", a[i]);
    }
}

void calfact() {
    vector<int> a(1, 1);
    int N =10;
    for (int i = 2; i <= N; ++i)
        multiply_by_scalar(a, i);
    print(a);
}

int NLCS(string X,string Y)
{
    int m = X.length(),n=Y.length();
    int i,j;
    for (i=0;i<=m;i++)
    {
        for (j=0;j<=n;j++)
        {
            if (i==0 || j==0)
                D[i][j]=1;
            else
            {
                D[i][j]=0;
                if (X[i-1]==Y[j-1])
                {
                    D[i][j]=D[i-1][j-1];
                }
                else
                {
                    if (L[i-1][j]==L[i][j])
                        D[i][j]=(D[i][j]+D[i-1][j])%23102009;
                    if (L[i][j-1]==L[i][j])
                        D[i][j]=(D[i][j]+D[i][j-1])%23102009;
                    if (L[i-1][j-1]==L[i][j])
                    {
                        if (D[i][j]<D[i-1][j-1])
                            D[i][j]+=23102009;
                        D[i][j]=(D[i][j]-D[i-1][j-1]);
                    }
                }
            }
        }
    }
    return (D[m][n]);
}