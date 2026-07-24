class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       if(nums.size()>=3){
        int maxnum= *max_element(nums.begin(), nums.end());
        int bits=0;
        while(maxnum){
            bits++;
            maxnum>>=1;
        }
        return 1<<bits;

       }
    return nums.size();    
    }
};