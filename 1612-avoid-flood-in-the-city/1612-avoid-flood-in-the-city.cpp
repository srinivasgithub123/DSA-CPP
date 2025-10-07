class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> lastRain;
        set<int> dryDays;
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (lastRain.count(lake)) {
                    int prevDay = lastRain[lake];
                    auto it = dryDays.lower_bound(prevDay);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                lastRain[lake] = i;
                ans[i] = -1;
            } else {
                dryDays.insert(i);
            }
        }

        return ans;
    }
};
