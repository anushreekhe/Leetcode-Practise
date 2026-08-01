class Solution {
public:

    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(j<0 || i>nums.size()-1 || i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first=nums[i]+min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
        int last=nums[j]+min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));
        return dp[i][j]= max(first,last);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
       
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=f(0,n-1,nums,dp);
        int sum=accumulate(nums.begin(),nums.end(),0);
        return 2*ans >= sum;
    }
};