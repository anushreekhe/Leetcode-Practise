class Solution {
public:

    int f(int i, vector<int>& arr, int k, vector<int>& dp){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0, maxi=INT_MIN, maxans=INT_MIN;
        for(int j=i; j<i+k && j<arr.size(); j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi) + f(j+1, arr, k, dp);
            maxans=max(maxans, sum);
        }
        return dp[i]=maxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return f(0, arr, k, dp);
    }
};