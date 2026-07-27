class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<int> st;

        // Collect all timestamps
        for (auto &x : series1)
            st.insert(x[0]);

        for (auto &x : series2)
            st.insert(x[0]);

        vector<vector<int>> ans;

        int p1 = 0, p2 = 0;

        for (int t : st) {

            // Move to the first timestamp >= t
            while (p1 < series1.size() && series1[p1][0] < t)
                p1++;

            while (p2 < series2.size() && series2[p2][0] < t)
                p2++;

            int value1 = (p1 == series1.size()) ? 0 : series1[p1][1];
            int value2 = (p2 == series2.size()) ? 0 : series2[p2][1];

            ans.push_back({t, value1 + value2});
        }

        return ans;
    }
};