class Solution {
public:

    // int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     int len=0+f(i+1,prev,nums,dp);
    //     if(prev==-1||nums[i]>nums[prev]){
    //         len=max(len,1+f(i+1,i,nums,dp));
    //     }
    //     return dp[i][prev+1]= len;
    // }

    int lengthOfLIS(vector<int>& nums) {
        
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        // return f(0,-1,nums,dp);

        int maxi=1;
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};