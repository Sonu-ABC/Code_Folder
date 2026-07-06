#include<bits/stdc++.h>


class Solution {
    
    int f(int curD, int i, int j, int n, vector<vector<vector<int>>>&dp){
        if(i>=4 || j>=3 || i<0 || j<0)return 0;
        if((i==3 && j==0)||(i==3 && j==2))return dp[curD][i][j]=0;
        if(curD==n)return dp[curD][i][j]=1;
        if(dp[curD][i][j]!=-1)return dp[curD][i][j];
        
        vector<int>delX;
        vector<int>delY;
        delX={-1,0,+1,0};
        delY={0,-1,0,+1};
        int sum=0;
        
        for(int idx=0;idx<4;idx++){
            int newR=i+delY[idx];
            int newC=j+delX[idx];
            sum+=f(curD+1,newR,newC,n,dp);
        }
        
        sum+=f(curD+1,i,j,n,dp);
        return dp[curD][i][j]=sum;
    }
  public:
    int getCount(int n) {
        // code here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans+=f(1,i,j,n,dp);
                //dp.assign(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
            }
        }
        return ans;
    }
};