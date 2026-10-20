class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = 0;  // values are >= 1, so 0 works as "-infinity"
            for (int start = 0; start < n && ok; start += k) {
                int descents = 0;
                int mn = INT_MAX, mx = INT_MIN;
                for (int i = 0; i < k; i++) {
                    int cur = nums[start + i];
                    int nxt = nums[start + (i + 1) % k];
                    if (cur > nxt) descents++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                if (descents > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return ans;
    }
};