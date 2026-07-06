class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_count=0, count0=0;
        int left=0, right=0;
        while(right<nums.size()){
            if(nums[right]==0){
                count0++;
            }    
                while(count0>k){
                    if(nums[left]==0)
                    count0--;
                    left++;
                }
                max_count= max(max_count, right-left+1);
                right++;
            
        }
    return max_count;     
    }
};