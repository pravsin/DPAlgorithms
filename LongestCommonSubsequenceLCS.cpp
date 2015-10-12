#include<bits/stdc++.h>

using namespace std;

string X,Y;
vector< vector<int> > c(101, vector<int>(101,0));
int m,n,ctr;

int LCSLength(string X,string Y)
{
    if (Y.length() > X.length())
        swap(X,Y);
    int m = X.length(),n=Y.length();
    vector< vector<int> > c(2, vector<int>(n+1,0));
    int i,j;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (X[i-1]==Y[j-1])
                c[1][j]=c[0][j-1]+1;
            else
                c[1][j]=max(c[1][j-1],c[0][j]);
        }
        for (j=1;j<=n;j++)
            c[0][j]=c[1][j];
    }
    return (c[1][n]);
}

void LCS()
{
    m = X.length(),n=Y.length();

    int i,j;
    for (i=0;i<=m;i++)
        for (j=0;j<=n;j++)
            c[i][j]=0;

    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            if (X[i-1]==Y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
}

void printLCS(int i,int j)
{
    if (i==0 || j==0)
        return;
    if (X[i-1]==Y[j-1])
    {
        printLCS(i-1,j-1);
        cout<<X[i-1];
    }
    else if (c[i][j]==c[i-1][j])
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}