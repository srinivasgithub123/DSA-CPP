// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int result= 0;

//         for(int i=0; i<nums.size(); i++){
//             int subarray_len= 0;
//             int count_target= 0;
//             for(int j=i; j<nums.size(); j++){
//                 subarray_len++;
//                 if(nums[j]==target){
//                     count_target+=1;
//                 }

//                 if(2*count_target> subarray_len){
//                     result++;
//                 }
//             }

//         }
//     return result;    
        
//     }
// };








class Solution{
public:
    int countMajoritySubarrays(vector<int>& nums, int target){
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int target_count=0, size=0;
            for(int j=i; j<nums.size(); j++){
                size++;
                if(nums[j]==target){
                    target_count++;
                }
                if(target_count>size/2){
                    ans++;
                }
            }
        }
    return ans;    
    }
};