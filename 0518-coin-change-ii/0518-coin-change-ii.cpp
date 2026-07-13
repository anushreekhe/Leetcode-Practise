class Solution {
public:

    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i==0) return (amount % coins[0] == 0) ? 1 : 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nottake=f(i-1,coins,amount,dp);
        int take=0;
        if(coins[i]<=amount) take=f(i,coins,amount-coins[i],dp);
        return dp[i][amount]=(take+nottake);
    }

    int change(int amount, vector<int>& coins) {
        if(coins.empty()) return amount==0 ? 1 : 0;
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return f(coins.size()-1, coins, amount,dp);
    }
};
