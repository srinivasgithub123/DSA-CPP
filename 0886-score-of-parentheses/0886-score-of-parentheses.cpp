class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // base level
        
        for(char c : s){
            if(c == '('){
                st.push(0);
            } else {
                int A = st.top();
                st.pop();
                int score = (A == 0) ? 1 : 2 * A;
                st.top() += score;
            }
        }
        return st.top();
    }
};
