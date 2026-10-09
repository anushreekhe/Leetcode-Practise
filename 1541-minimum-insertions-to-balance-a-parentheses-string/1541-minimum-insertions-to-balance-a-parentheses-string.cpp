class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int c=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('){
                if(c==1){
                    count++;
                    if(st.empty()) count++;
                    else st.pop();
                    c=0;
                }
                st.push(0);
            }
            else{
                c+=1;
                if(c==2){
                    if(st.empty()) count++;
                    else st.pop();
                    c=0;
                }
                
                
                

        }
        
        
    }
    if(c==1){
        count++;
        if(st.empty()) count++;
        else st.pop();

    }
    count+=st.size()*2;
    return count;
}};