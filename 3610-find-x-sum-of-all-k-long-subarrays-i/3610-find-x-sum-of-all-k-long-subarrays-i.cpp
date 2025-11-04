class Solution {
public:

    // Helper function to compute the "x-sum" of the current window
    // -------------------------------------------------------------
    // Steps:
    // 1. Copy all elements and their frequencies into a vector of pairs
    // 2. Sort the vector by frequency (descending) and value (descending)
    // 3. Take only the top 'x' elements and sum up (value * frequency)
    int computeXsum(unordered_map<int, int> freq, int x) {
        vector<pair<int, int>> vec;

        // Copy (element, frequency) pairs from unordered_map to vector
        for (auto it = freq.begin(); it != freq.end(); it++) {
            vec.push_back(make_pair(it->first, it->second));
        }

        // Sort vector manually:
        //   - Higher frequency comes first
        //   - If frequency is same, higher value comes first
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j].second > vec[i].second || 
                    (vec[j].second == vec[i].second && vec[j].first > vec[i].first)) {
                    pair<int, int> temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }

        // Calculate sum of only the top 'x' most frequent elements
        int sum = 0;
        for (int i = 0; i < x && i < vec.size(); i++) {
            sum += vec[i].first * vec[i].second;
        }

        return sum;
    }

    // Main function to compute x-sum for every window of size k
    // ---------------------------------------------------------
    // Uses a sliding window + frequency map approach
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;                  // Final answer array
        unordered_map<int, int> freq;     // Frequency map for current window

        // Slide window from left to right
        for (int i = 0; i < n; i++) {
            // Step 1: Include current element in the frequency map
            freq[nums[i]]++;

            // Step 2: Once we have a full window (i >= k - 1)
            if (i >= k - 1) {
                // Compute x-sum for current window
                int sum = computeXsum(freq, x);
                ans.push_back(sum);

                // Step 3: Remove the leftmost element (slide window)
                // -----------------------------------------------
                // Only one copy of the leftmost element leaves the window.
                // If its frequency becomes 0, erase it completely.
                int left = nums[i - k + 1];
                freq[left]--;
                if (freq[left] == 0) {
                    freq.erase(left);
                }
            }
        }

        // Step 4: Return x-sum for all windows
        return ans;
    }
};
