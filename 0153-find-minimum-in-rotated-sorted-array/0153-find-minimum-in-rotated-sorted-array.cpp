// // class Solution {
// // public:
// //     int findMin(vector<int>& nums) {
// //         int low = 0, high = nums.size() - 1;

// //         while (low < high) {
// //             int mid = low + (high - low) / 2;

// //             // If mid element > high element → min is in right half
// //             if (nums[mid] > nums[high]) {
// //                 low = mid + 1;
// //             } 
// //             // Otherwise → min is in left half (including mid)
// //             else {
// //                 high = mid;
// //             }
// //         }
// //         return nums[low];  // low == high at the end
// //     }
// // };














// class Solution{
// public:
//     int findMin(vector<int>& nums){
//         int left= 0, right= nums.size()-1;
//         while(left < right){
//             int mid= left+(right- left)/2;
//             if(nums[mid]>nums[right]){
//                 left= mid+1;
//             }else if(nums[mid]<nums[right]){
//                 right= mid;
//             }
 
//         }

//     return nums[left];    
//     }
// };


































class Solution{
public:
    int findMin(vector<int>& nums){
        int left=0, right= nums.size()-1;
        while(left<right){
            int mid= left+(right-left)/2;

            if(nums[mid]>nums[right]){
                left= mid+1;
            }else{
                right= mid;
            }
            
        }

    return nums[left];    
    }
};