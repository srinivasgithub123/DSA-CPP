#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for (int x : nums) if (x == 1) ++cnt1;
        if (cnt1 > 0) return n - cnt1; // each non-1 needs one operation to become 1

        // overall gcd
        int g = 0;
        for (int x : nums) g = std::gcd(g, x);
        if (g > 1) return -1; // impossible to get 1 anywhere

        // find shortest subarray with gcd == 1
        int best = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                cur = std::gcd(cur, nums[j]);
                if (cur == 1) {
                    best = min(best, j - i + 1);
                    break;
                }
            }
        }

        // make one 1 inside that subarray takes (L-1) ops, then spread to others (n-1) ops
        return n + best - 2;
    }
};
