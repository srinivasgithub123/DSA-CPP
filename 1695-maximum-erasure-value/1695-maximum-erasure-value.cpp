class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums){
        int sum=0, res=0, left=0;
        unordered_set<int>st;
        for(int right=0; right<nums.size(); right++){
            if(st.find(nums[right])==st.end()){
                sum=sum+nums[right];
                st.insert(nums[right]);
            }else{
                while(st.count(nums[right])){
                    sum=sum-nums[left];
                    st.erase(nums[left]);
                    left++;
                }
                sum=sum+nums[right];
                st.insert(nums[right]);

            }

            res= max(res, sum);

        }
    return res;    
    }
};