class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int>ans(0,2);
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second>1){
                ans.push_back(it->first);
            }
        }
        return ans;
        
    }
};