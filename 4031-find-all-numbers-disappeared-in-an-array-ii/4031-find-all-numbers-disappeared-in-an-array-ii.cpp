class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        vector<int>freq(100001, 0);
        for(auto it: nums){
            freq[it]=1;
        }

        int left= lower, right= lower-1, len=0;
        for(int i=lower; i<=upper; i++){
            if(freq[i]==0){
                right++;
                len++;
            }else{
                if(len>0){
                    ans.push_back({left, right});
                }

                left= i+1;
                right=i;
                len=0;
            }
        }

        if(len>0){
            ans.push_back({left, right});
        }

        return ans;
        
    }
};