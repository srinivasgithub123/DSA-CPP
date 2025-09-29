class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()&&s[i]==st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(st.size()!=0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};