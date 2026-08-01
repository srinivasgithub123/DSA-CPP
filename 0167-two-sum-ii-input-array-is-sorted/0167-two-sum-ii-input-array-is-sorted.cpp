// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int k) {
//         int n=nums.size();
//         int l=0, h=n-1;
//         while(l<h){
//             int s=nums[l]+nums[h];
//             if(s==k){
//                 return {l+1,h+1};
//             }
//             else if(s<k) l++;
//             else h--;
//         }
//         return {};
//     }
// };















class Solution{
public:
    vector<int>twoSum(vector<int>nums, int target){
        int left=0 , right= nums.size()-1;
        vector<int>ans;
        while(left<right){
            int sum= nums[left]+nums[right];
            if(sum> target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
        }
    return ans;    
    }
};