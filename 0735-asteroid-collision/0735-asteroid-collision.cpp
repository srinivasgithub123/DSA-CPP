class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;

        for (int a : nums) {
            bool destroyed = false;

            // Check collisions only if a is moving left
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    st.pop(); // stack asteroid smaller → destroyed
                    continue; // keep checking
                } else if (st.top() == -a) {
                    st.pop(); // both destroyed
                }
                destroyed = true; // current asteroid destroyed
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> res(st.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
