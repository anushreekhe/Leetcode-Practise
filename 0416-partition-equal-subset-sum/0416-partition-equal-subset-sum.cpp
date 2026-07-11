class Solution {
public:

    bool f(int i, vector<int>& nums, int s, vector<vector<int>>& dp){
        if(s==0) return true;
        if(i==0) return nums[0]==s;
        if(dp[i][s]!=-1) return dp[i][s];
        bool nottake=f(i-1,nums,s,dp);
        bool take=false;
        if(nums[i]<=s) take=f(i-1,nums,s-nums[i],dp);
        return dp[i][s]=nottake | take;
    }

    bool canPartition(vector<int>& nums) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0) return false;
       vector<vector<int>> dp(nums.size(), vector<int>(sum+1,-1));
       return f(nums.size()-1,nums,sum/2,dp); 
    }
};