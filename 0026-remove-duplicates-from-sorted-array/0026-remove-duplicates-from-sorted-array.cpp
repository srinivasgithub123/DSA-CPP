// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int j=0;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]!=nums[i-1]){
//                 j++;
//                 nums[j]=nums[i];
//             }
//         }
//         return j+1;
//     }
// };













class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int left=0, right=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[left]!=nums[right]){
                left++;
                nums[left]=nums[right];
            }
            right++;
        } 
    return left+1;    
    }
};