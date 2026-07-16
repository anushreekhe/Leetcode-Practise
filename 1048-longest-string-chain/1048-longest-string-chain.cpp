class Solution {
public:


    

    bool compare(string a, string b){
    if(b.size()-a.size()!=1) return 0;
    int i=0, j=0;
    bool skipped = false;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            i++; j++;
        } else {
            if(skipped) return 0; // already skipped once, can't skip again
            skipped = true;
            j++;
        }
    }
    return true;
}

    int longestStrChain(vector<string>& words) {
        int maxi=1;
        sort(words.begin(), words.end(), [](const string&a, const string&b){
    return a.size() < b.size();
});
        vector<int> dp(words.size(),1);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compare(words[j],words[i])){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};