class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=0; int last=0;
        //s=trim(s);
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1 && s[i]!=' '){
                last=l+1;
                break;
            }
            if(i!=0 && s[i]==' ' && s[i-1]!=' '){
                last=l;
                l=0;
            }
            else if(i!=0 && s[i]==' ' && s[i-1]==' ') continue;
            else if(i==0 && s[i]==' ') continue;
            else{
                l++;
            }
        }
        return last;
    }
};