class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        char ans;
        for(int i=0;i<expression.size();i++){
            
            while(i < expression.size() && expression[i]!=')'){
                s.push(expression[i]);
                i++;
            }
            if(i < expression.size() && expression[i]==')'){
                int t=0, f=0;
                while(s.top()!='('){
                    char l=s.top();
                    if(l=='t') t++;
                    else if(l=='f') f++;
                    s.pop();
                }
                s.pop();
                char fun=s.top();
                s.pop();
                if(fun=='!'){
                    if(t>0) s.push('f');
                    else if(f>0) s.push('t');
                } 
                else if(fun=='&'){
                    if(f>0) s.push('f');
                    else s.push('t');
                }
                else if(fun=='|'){
                    if(t>0) s.push('t');
                    else s.push('f');
                }
            }
            if(s.size()==1){
                ans=s.top();
                break;
            }
        }
        if(ans=='t') return true;
        else return false;
    }
};