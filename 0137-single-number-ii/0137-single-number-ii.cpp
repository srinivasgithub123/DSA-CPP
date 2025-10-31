class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for(int n: nums){
        // Update ones and twos
        ones = (ones ^ n) & ~twos;
        twos = (twos ^ n) & ~ones;
        }
        return ones;
        
    }
};