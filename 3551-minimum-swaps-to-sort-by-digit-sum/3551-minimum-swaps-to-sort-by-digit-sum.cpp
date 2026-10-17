class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int s = 0;
            while (num != 0) {
                s += num % 10;
                num /= 10;
            }
            vec[i][0] = s;
            vec[i][1] = nums[i];
            vec[i][2] = i;
        }
        sort(vec.begin(), vec.end());

        vector<bool> vis(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cycles++;
                int j = i;
                while (!vis[j]) {
                    vis[j] = true;
                    j = vec[j][2];
                }
            }
        }
        return n - cycles;
    }
};