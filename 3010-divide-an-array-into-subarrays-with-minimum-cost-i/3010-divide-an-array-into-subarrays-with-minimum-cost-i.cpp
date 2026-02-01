class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans= INT_MAX;
        for(int i=1; i<=nums.size()-2; i++){
            for(int j=i+1; j<=nums.size()-1; j++){
                ans= min(ans, nums[0]+nums[i]+nums[j]);
            }
        }

        return ans;
        
    }
};