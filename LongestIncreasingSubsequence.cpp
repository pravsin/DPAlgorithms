#include<bits/stdc++.h>
using namespace std;

long LongestIncreasingSubsequence(vector<int> arr){
    long n = arr.size();
    map<int,int> m;
    vector<int> pre(n,-1),res;
    map<int,int> ::iterator k, l;
    for (int i = 0; i < n; ++i) {
        if(m.insert(make_pair(arr[i],i)).second){
            k = m.find(arr[i]);
            l =k;k++;
            if(l==m.begin()){
                pre[i]=-1;
            }
            else{
                l--;
                pre[i]=l->second;
            }
            if(k!=m.end())
                m.erase(k);
        }
    }
    k = m.end();
    k--;
    int j = k->second;
    while(j!=-1){
        res.push_back(arr[j]);
        j = pre[j];
    }
    int nn= (int) (res.size()-1);
    for (int i1 =nn ; i1 >=0 ; --i1) {
        cout<<res[i1]<<" ";
    }
    return nn+1;
}