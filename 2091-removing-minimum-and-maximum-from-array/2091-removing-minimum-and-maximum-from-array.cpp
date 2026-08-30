class Solution {
public:

    int minimumDeletions(vector<int>& nums) {
        int minidx=0, maxidx=0, mini=nums[0], maxi= nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxi){
                maxi= nums[i];
                maxidx=i;
            }else if(nums[i]<mini){
                mini= nums[i];
                minidx=i;
            }
        }

        int left= max(minidx,maxidx)+1;
        int right= nums.size()-min(minidx, maxidx);
        int both;
        if(maxidx < minidx){
            both= (maxidx+1) + (nums.size()-minidx);
        }else{
            both= (minidx+1) + (nums.size()- maxidx);
        }

        int ans= min({left, right, both});
        return ans;
        
    }
};