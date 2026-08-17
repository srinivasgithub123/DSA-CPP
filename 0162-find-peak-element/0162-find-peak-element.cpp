// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int l=0, r=nums.size()-1;
//         while(l<r){
//             int mid=(l+r)/2;
//             if(nums[mid]<nums[mid+1])
//             l=mid+1;
//             else
//             r=mid;

//         }
//         return l;
        
//     }
// };














class Solution{
public:
    int findPeakElement(vector<int>& nums){
        int left=0, right= nums.size()-1;

        while(left<right){
            int mid= left+(right-left)/2;

            if(nums[mid]<nums[mid+1]){
                left= mid+1;
            }else if(nums[mid]>nums[mid+1]){
                right= mid;
            }
        }
    return left;    
    }
};