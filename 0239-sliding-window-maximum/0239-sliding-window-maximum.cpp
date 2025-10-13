class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans(nums.size()-k+1);
        // for(int i=0; i<=nums.size()-k; i++){
        //     int maxnum=nums[i];
        //     for(int j=i; j<i+k; j++){
        //         maxnum=max(maxnum, nums[j]);
        //     }
        //     ans[i]=maxnum;
        // }
        // return ans;
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove indices outside the window
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            // Add maximum for the current window
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};