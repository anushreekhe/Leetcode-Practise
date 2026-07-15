class Solution {
public:

    int f(int i, vector<int>& prices, int buy, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        long profit=0;
        if(buy==1){
            profit=max(-prices[i]+f(i+1,prices,0,dp), 0+f(i+1,prices,1,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,prices,1,dp), 0+f(i+1,prices,0,dp));
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,prices,1, dp);
    }
};