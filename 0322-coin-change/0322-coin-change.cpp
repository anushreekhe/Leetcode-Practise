class Solution {
public:

    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nottake=f(i-1,coins,amount,dp);
        int take=1e9;
        if(coins[i]<=amount) take=1+f(i,coins,amount-coins[i],dp);
        return dp[i][amount]=min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        if(amount<coins[0]) return -1;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans= f(coins.size()-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};