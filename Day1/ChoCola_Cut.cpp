#include<bits/stdc++.h>

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        
        int vS=1;
        int hS=1;
        int cost=0;
        int ptrx=0,ptry=0;
        
        while(ptrx<x.size() && ptry<y.size()){
            if(x[ptrx]>y[ptry]){
                vS++;
                cost+=hS*(x[ptrx]);
                ptrx++;
            }
            else{
                hS++;
                cost+=vS*(y[ptry]);
                ptry++;
            }
        }
        while(ptrx<x.size()){
              vS++;
                cost+=hS*(x[ptrx]);
                ptrx++;
        }
        
        while(ptry<y.size()){
             hS++;
                cost+=vS*(y[ptry]);
                ptry++;
        }
        
        return cost;
    }
};
