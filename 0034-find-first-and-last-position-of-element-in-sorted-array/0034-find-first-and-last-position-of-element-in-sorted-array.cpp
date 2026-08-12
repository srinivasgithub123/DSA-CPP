// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int tar) {
//         vector<int> ans;
//         int st = 0, end = nums.size() - 1;
//         if(nums.size()==1 && nums[0]==tar)
//         return {0,0};

//         while (st <= end) {
//             int mid = (st + end) / 2;
//             if (nums[mid] == tar) {
//                 if (mid > 0 && nums[mid] == nums[mid - 1]) {
//                     ans.push_back(mid - 1);
//                     ans.push_back(mid);
//                 }
//                 else{
//                     ans.push_back(mid);
//                     ans.push_back(mid + 1);
//                 }
//                 return ans;
//             }
//             else if (nums[mid] < tar)
//                 st = mid + 1;
//             else
//                 end = mid - 1;
//         }
        
//         // If not found, return {-1, -1}
//         return {-1, -1};
//     }
// };
















class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
       vector<int>ans;
       int left=0, right= nums.size()-1, first=-1;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(target>nums[mid]){
                left= mid+1;
            }else if(target<nums[mid]){
                right= mid-1;
            }else{
                first= mid;
                right= mid-1;
            }
        }

        if(first==-1) return {-1, -1};

        left=0, right= nums.size()-1;
        int last= first;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(target>nums[mid]){
                left= mid+1;
            }else if(target<nums[mid]){
                right= mid-1;
            }else{
                last= mid;
                left= mid+1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
