class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result= 0;

        for(int i=0; i<nums.size(); i++){
            int subarray_len= 0;
            int count_target= 0;
            for(int j=i; j<nums.size(); j++){
                subarray_len++;
                if(nums[j]==target){
                    count_target+=1;
                }

                if(2*count_target> subarray_len){
                    result++;
                }
            }

        }
    return result;    
        
    }
};