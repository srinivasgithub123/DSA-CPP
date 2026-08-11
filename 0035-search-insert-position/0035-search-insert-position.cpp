// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int tar) {
//         int st=0,end=nums.size()-1;
//         while(st<=end){
//             int mid=(st+end)/2;
//             if(nums[mid]==tar)
//             return mid;
//             else if(tar>nums[mid])
//             st=mid+1;
//             else
//             end=mid-1;
//         }
//         return st;
        
//     }
// };













class Solution{
public:
    int searchInsert(vector<int>& nums, int target){
        int left=0, right= nums.size()-1;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(target<nums[mid]){
                right= mid-1;
            }else if(target>nums[mid]){
                left= mid+1;
            }else{
                return mid;
            }
        }

        return left;
    }
};