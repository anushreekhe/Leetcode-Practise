class Solution {
public:

    int houseRobber(vector<int> numb){
        int n=numb.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max(numb[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> case2(nums.begin() + 1, nums.end());
        int dp1=houseRobber(case1);
        int dp2=houseRobber(case2);
        return max(dp1,dp2);
    }
};