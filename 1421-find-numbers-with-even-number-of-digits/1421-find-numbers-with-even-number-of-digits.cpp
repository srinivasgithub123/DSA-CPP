class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans= 0;
        /*for(int val: nums){
            ans+=int(floor(log10(val))+1)%2==0;
        }
        return ans;*/

        for(int val: nums){
            if((val>9 && val< 100) || (val>999 && val<10000) || (val==100000)){
                ans++;
            }
        }
        return ans;
        
    }
};