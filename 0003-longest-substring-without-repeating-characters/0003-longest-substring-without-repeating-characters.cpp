class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        unordered_map<int, int> mp;
        for (int c = 0; c < 256; c++) {
            mp[c] = -1;
        }
        int n=s.size();
        while(r<n){
            if(mp[s[r]]!=-1){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            mp[s[r]]=r;
            r++;

        }
        return maxLen;
    }
};