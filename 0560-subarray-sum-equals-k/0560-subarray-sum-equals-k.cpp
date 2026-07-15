// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//        int count=0;
//        unordered_map<int, int>prefixsum;
//        prefixsum[0]=1;
//        int sum=0;
//        for(int i=0; i<nums.size(); i++){
//         sum+=nums[i];
//         if(prefixsum.find(sum-k)!=prefixsum.end()){
//             count+=prefixsum[sum-k];
//         }
//         prefixsum[sum]++;
//        }
        
//         return count;
//     }
// };














class Solution{
public:
    int subarraySum(vector<int>& nums, int k){
        int ans=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        int cs=0;

        for(int i=0; i<nums.size(); i++){
            cs+=nums[i];
            if(freq.count(cs-k)){
                ans+=freq[cs-k];
            }
            freq[cs]++;
        }
        
    return ans;    
    }
};