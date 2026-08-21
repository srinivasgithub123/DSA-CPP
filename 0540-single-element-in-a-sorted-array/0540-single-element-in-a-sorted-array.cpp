// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n=nums.size(),st=0,end=n-1,mid;
//         if(n==1)
//         return nums[0];
//         while(st<=end){
//             mid=st+(end-st)/2;
//             if(mid==0 && nums[0]!=nums[1])
//             return nums[mid];
//             if(mid==n-1 && nums[n-1]!=nums[n-2])
//             return nums[mid];
//             if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
//             return nums[mid];
//             if(mid%2==0){
//                     if(nums[mid]==nums[mid-1])
//                     end=mid-1;
//                     else
//                     st=mid+1;
//             }
//             else{
//                if(nums[mid]==nums[mid-1])
//                st=mid+1;
//                else
//                end=mid-1;
//             }
//         }
//         return -1;
        
//     }
// };













class Solution{
public:
    int singleNonDuplicate(vector<int>& nums){
        int left= 0, right= nums.size()-1;

        while(left<right){
            int mid= left+(right-left)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            else if(nums[mid]==nums[mid-1]){
                if((mid-1-left)%2!=0){
                    right= mid-2;
                }else{
                    left= mid+1;
                }
            }

            else if(nums[mid]==nums[mid+1]){
                if((right-mid+1)%2!=0){
                    left= mid+2;
                }else{
                    right= mid-1;
                }
            }
        }

    return nums[left];    
    }
};