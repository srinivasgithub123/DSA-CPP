class Solution {
public:

    bool capacity(int wt, vector<int>& weights, int days) {
        int sum = 0;
        int tdays = 1;

        for (auto it : weights) {

            if (sum + it > wt) {
                tdays++;
                sum = it;
            } else {
                sum += it;
            }
        }

        return tdays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;

        for (auto it : weights) {
            total += it;
        }

        int left = *max_element(weights.begin(), weights.end());
        int right = total;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (capacity(mid, weights, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};