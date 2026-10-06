class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(ch=='('){
                st.push(ch);
            }else{
                if(st.top()=='('){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};