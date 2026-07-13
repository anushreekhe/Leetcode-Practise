class Solution {
public:

    int f(int i, vector<int>& nums, int target, vector<vector<int>>& dp,int offset){
        if(i==0){
        if(nums[0]==0){
            return (target==0) ? 2 : 0;
        }
        return (target==nums[0] || target==-nums[0]) ? 1 : 0;
        }
        if(target+offset < 0 || target+offset > 2*offset) return 0;
        if(dp[i][target+offset]!=-1) return dp[i][target+offset];
        int plus=f(i-1,nums,target-nums[i],dp,offset);
        int minus=f(i-1,nums,target+nums[i],dp,offset);
        return dp[i][target+offset]=plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(n==0) return (target==0?0:-1);
        if(target>sum || target<-sum) return 0;
        int offset=sum;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return f(n-1,nums,target,dp,offset);
    }
};