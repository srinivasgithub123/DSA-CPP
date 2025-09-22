class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>m;
        int freq=0, count=0;

        for(int val: nums)
        m[val]++;
        
        for(auto& pair: m){
            if(pair.second == freq)
            count++;
            else if(pair.second > freq){
                freq= pair.second;
                count=1;
            }
        }

        return count*freq;
    }
};