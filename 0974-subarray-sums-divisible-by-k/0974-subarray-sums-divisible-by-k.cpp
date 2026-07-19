class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, cs=0;
        unordered_map<int, int>freq;
        freq[0]=1;
        for(int i=0; i<nums.size(); i++){
            cs+=nums[i];
            int rem=cs%k;
            if(rem<0)
            rem+=k;
            
            ans+=freq[rem];
            freq[rem]++;
            
        }
    return ans;    
        
    }
};