#include<bits/stdc++.h>
using namespace std;

long long histogramArea(vector<int> &histo){
    stack<int> s;
    long long maxArea=0;
    long long area= 0;
    int i =0;
    for (i = 0; i < histo.size();) {
        if(s.empty() || histo[s.top()] <= histo[i]){
            s.push(i++);
        }
        else{
            int top = s.top(); s.pop();
            area= histo[top]* (s.empty()?i:i-s.top()-1);
            if(area >maxArea)
                maxArea= area;
        }
    }
    while(!s.empty()){
        int top = s.top();s.pop();
        area= histo[top]* (s.empty()?i:i-s.top()-1);
        if(area >maxArea)
            maxArea= area;
    }
    return maxArea;
}