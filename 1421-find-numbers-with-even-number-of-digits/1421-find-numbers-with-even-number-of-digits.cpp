class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans= 0;
        for(int val: nums){
            ans+=int(floor(log10(val))+1)%2==0;
        }
        return ans;
        
    }
};