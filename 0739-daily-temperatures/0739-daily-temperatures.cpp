class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> answer(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                answer[i]=0;
                st.push(i);
                continue;
            }
            if(!st.empty() && temperatures[i]<temperatures[st.top()]){
                answer[i]=1;
                st.push(i);
                continue;
            }
            else{
                while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
                if(st.empty()){
                    answer[i]=0;
                    st.push(i);
                    continue;
                }
                answer[i]=st.top()-i;
                st.push(i);
            }
        }
        return answer;
    }
};