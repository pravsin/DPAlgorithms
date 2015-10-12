#include<bits/stdc++.h>
using namespace std;

#define SIZE 31
#define INF 1e8
double dis[SIZE][SIZE];
/*
 * use the algorithm to find the shortest path
    find negative cycles in a graph.
        If the value of any of the diagonal elements is less than zero after calling the floyd-warshall algorithm then there is a negative cycle in the graph.
    find transitive closure
        to find if there is a path between two vertices we can use a boolean matrix and use and-& and or-| operators in the floyd_warshall algorithm.
    to find the number of paths between any two vertices we can use a similar algorithm.
 */
void init(int N)
{
    int i,j,k;
    for (k=0;k<N;k++)
        for (i=0;i<N;i++)
            dis[i][j]=INF;
}
void floyd_warshall(int N)
{
    int i,j,k;
    init(N);
    //Read values in dis[][]
    for (k=0;k<N;k++)
        for (i=0;i<N;i++)
            for (j=0;j<N;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}