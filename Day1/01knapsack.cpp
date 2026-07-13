#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>val, vector<int>wt, int W, int n){
    if(W==0 || n==0){
        return 0;
    }
    if(wt[n-1]<=W){
        //include
        int ans1 = val[n-1]+knapsack(val,wt,W-wt[n-1],n-1);
        //exclude
        int ans2 = knapsack(val,wt,W,n-1);
        return max(ans1,ans2);
    }
    else{
        return knapsack(val, wt, W,n-1);
    }
}

int main(){
    vector<int>val;
    val={15,14,10,45,30};
    vector<int>wt;
    wt={2,5,1,3,4};
    int W = 7;
    int ans = knapsack(val,wt,W,5);
    cout<<ans;
    return 0;
}