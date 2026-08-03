// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int idx=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=val){
//                 swap(nums[idx], nums[i]);
//                 idx++;
//             }
//         }
//         return idx;
        
//     }
// };











class Solution{
public:
     int removeElement(vector<int>& nums, int val){
       int left=-1, right=0;
       for(right=0; right<nums.size(); right++){
        if(nums[right]==val){
            continue;
        }
        else{
            left++;
            nums[left]=nums[right];
        }
       } 
    return left+1;    
     }
};