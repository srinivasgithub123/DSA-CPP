class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cs=0, ans=0;
        unordered_map<int, int>freq;
        freq[0]=1;
        for(int i=0; i<nums.size(); i++){
            cs+=nums[i];
            if(freq.count(cs-goal)){
                ans+=freq[cs-goal];
            }
            freq[cs]++;
        }
    return ans;    
        
    }
};