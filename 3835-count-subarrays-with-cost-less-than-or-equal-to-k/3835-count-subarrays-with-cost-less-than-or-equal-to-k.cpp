class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       int l=0, n=nums.size();
       long long ans=0;
       multiset<int>ms;
       for(int r=0; r<n; r++){
        ms.insert(nums[r]);

        while(!ms.empty() && (long long)(*ms.rbegin() - *ms.begin()) * (r - l + 1) > k){
            ms.erase(ms.find(nums[l]));
            l++;
        }

        ans+=(r-l+1);
       }

       return ans;  
    }

};