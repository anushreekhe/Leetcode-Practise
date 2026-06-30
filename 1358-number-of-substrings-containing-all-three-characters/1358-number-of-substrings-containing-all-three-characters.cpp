class Solution {
public:
    int numberOfSubstrings(string s) {
        int l[3]={-1,-1,-1};
        long long c=0;
        for(int i=0;i<s.size();i++){
            l[s[i]-'a']=i;
            int minl=min({l[0],l[1],l[2]});
            if(minl!=-1) c+=minl+1;
        }
        return c;
    }
};