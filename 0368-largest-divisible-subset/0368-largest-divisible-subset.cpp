class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());   // sabse pehle sort — divisibility ka order chahiye

        vector<int> dp(n, 1), hash(n);
        int maxi = 0;   // sabse lambi chain ka length track karega

        for(int i=0; i<n; i++){
            hash[i] = i;   // default: khud se hi start hoti hai chain
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;   // yaad rakho kaha se aaye
                }
            }
            if(dp[i] > dp[maxi]) maxi = i;   // sabse lambi chain kaha khatam hui
        }

        // backtrack karke actual subset nikalo
        vector<int> ans;
        int temp = maxi;
        while(hash[temp] != temp){
            ans.push_back(nums[temp]);
            temp = hash[temp];
        }
        ans.push_back(nums[temp]);   // last element bhi daalo

        reverse(ans.begin(), ans.end());
        return ans;
    }
};