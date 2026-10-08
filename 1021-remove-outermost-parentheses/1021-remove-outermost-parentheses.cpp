class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
                if(c>1) ans=ans+s[i];
            }
            else{
                c--;
                if(c>0) ans=ans+s[i];
            }
            
           
        }
        return ans;
    }
};