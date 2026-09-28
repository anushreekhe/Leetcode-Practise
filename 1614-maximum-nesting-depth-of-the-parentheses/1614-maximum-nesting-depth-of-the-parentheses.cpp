class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,c=0;
        for(int i=0;i<s.size();i++){
            char a=s[i];
            if(a=='('){
                c++;
                if(c>maxi) maxi=c;
            }
            else if(a==')') c--;
        }
        return maxi;
    }
};