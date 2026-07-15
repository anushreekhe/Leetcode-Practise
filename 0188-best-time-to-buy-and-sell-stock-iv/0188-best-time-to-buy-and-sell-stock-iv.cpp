class Solution {
public:

    int f(int i, vector<int>& prices, int buy, vector<vector<vector<int>>>& dp, int cap){
        if(i==prices.size() || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        long profit=0;
        if(buy==1){
            profit=max(-prices[i]+f(i+1,prices,0,dp,cap), 0+f(i+1,prices,1,dp,cap));
        }
        else{
            profit=max(prices[i]+f(i+1,prices,1,dp,cap-1), 0+f(i+1,prices,0,dp,cap));
        }
        return dp[i][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0,prices,1, dp,k);
    }
};