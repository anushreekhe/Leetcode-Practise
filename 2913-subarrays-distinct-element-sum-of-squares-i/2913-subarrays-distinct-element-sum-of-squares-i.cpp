class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> seen(101, 0);
            int dist = 0;
            for (int j = i; j < n; j++) {
                if (seen[nums[j]] == 0) {
                    seen[nums[j]] = 1;
                    dist++;
                }
                ans += dist * dist;
            }
        }
        return ans;
    }
};