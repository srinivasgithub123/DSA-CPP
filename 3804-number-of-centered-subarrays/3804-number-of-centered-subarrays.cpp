class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count=0, n= nums.size();
        for(int i=0; i<n; i++){
            long long sum=0;
            for(int j=i; j<n; j++){
                sum=sum+nums[j];
                for(int k=i; k<=j; k++){
                    if(nums[k]==sum){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};