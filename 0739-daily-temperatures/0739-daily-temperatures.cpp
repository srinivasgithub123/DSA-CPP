class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st; // will store indices of days

        for(int i = n-1; i >= 0; i--) {
            // Pop all smaller/equal temperatures
            while(!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }

            // If stack not empty, nearest warmer day is st.top()
            if(!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Push this day's index
            st.push(i);
        }

        return ans;
    }
};
