class Solution {
public:
    int minOperations(string s) {
        string t=s;
        int n=s.size();
        sort(t.begin(),t.end());
        if(s==t) return 0;
        if(s.size()==2 and s!=t) return -1;
        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;
       
            for(int i=0;i<n-1;i++){
                if(t[0]==s[i]) return 2;
            }
            
       
            for(int i=1;i<n;i++){
                if(t[n-1]==s[i]) return 2;
            }
            
       
        return 3;
    }
};