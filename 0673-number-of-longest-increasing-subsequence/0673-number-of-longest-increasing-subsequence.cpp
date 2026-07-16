class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=1;
        vector<int> dp(nums.size(),1), cnt(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i] ){
                    dp[i]=max(dp[i], 1+dp[j]);
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i] ){
                    cnt[i]+=cnt[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi) c+=cnt[i];
        }
        return c;
    }
};