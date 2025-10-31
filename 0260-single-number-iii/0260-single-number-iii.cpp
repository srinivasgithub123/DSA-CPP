class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall=0;
        for(int n: nums){
            xorall^=n;
        }

        long long diffbit=xorall & -xorall;

        int a=0, b=0;
        for(int n: nums){
            if(n&diffbit){
                a^=n;
            }else{
                b^=n;
            }
        }
        return {a,b};
        
    }
};