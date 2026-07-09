// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int ans=0;
//         for(int i=0; i<nums.size(); i++){
//             unordered_map<int, int>mp;
//             for(int j=i; j<nums.size(); j++){
//                 mp[nums[j]]++;
//                 if(mp.size()==k){
//                     ans++;
//                 }

//                 if(mp.size()>k){
//                     break;
//                 }

//             }
//         }
//     return ans;    
//     }
// };









class Solution {
public:

    int atMostK(vector<int>&nums, int k){
        unordered_map<int, int>mp;
        int left=0, right=0, ans=0;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k){
           return atMostK(nums, k)-atMostK(nums, k-1);
        }
    };