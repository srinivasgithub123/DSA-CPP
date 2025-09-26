class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=0;
        int n= nums.size(), j, k;
        for(int i=n-1; i>=0; i--){
            j=i-1,k=0;
            while(k<j){
                if(nums[j]+nums[k]>nums[i]){
                    c+=(j-k);
                    j--;
                }
                else{
                    k++;
                }
            }
        }
        return c;
    }
};