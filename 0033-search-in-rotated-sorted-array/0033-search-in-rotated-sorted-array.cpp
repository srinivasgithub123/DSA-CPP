// class Solution {
// public:
//     int search(vector<int>& nums, int tar) {
//         int st=0,end=nums.size()-1,mid;
//         while(st<=end){
//             mid=st+(end-st)/2;
//             if(tar==nums[mid])
//             return mid;
//             if(nums[st]<=nums[mid]){//left sorted
//                 if(nums[st]<=tar && tar<=nums[mid])
//                 end=mid-1;
//                 else
//                 st=mid+1;
//             }
//             else{//right half sorted
//                 if(nums[mid]<=tar && tar<=nums[end])
//                 st=mid+1;
//                 else
//                 end=mid-1;
//             }
//         }
//         return -1;
        
//     }
// };














class Solution{
public:
    int search(vector<int>& nums, int target){
        int left= 0, right= nums.size()-1;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(target==nums[mid]){
                return mid;
            }
            
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<=nums[mid]){
                    right= mid-1;
                }else{
                    left= mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[right]){
                    left= mid+1;
                }else{
                    right= mid-1;
                }
            }
        }
       return -1;
    }
};