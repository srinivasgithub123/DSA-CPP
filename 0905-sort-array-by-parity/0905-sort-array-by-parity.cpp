class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=-1, right;
        for(right=0; right<nums.size(); right++){
            if(nums[right]%2==0){
                left++;
                swap(nums[left], nums[right]);
            }
        }
    return nums;    
        
    }
};