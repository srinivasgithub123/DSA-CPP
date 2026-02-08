// class Solution {
// public:
//     int dominantIndices(vector<int>& nums) {
//         int n= nums.size();
//         int dom=0;
//         if(n<1)return 0;
//         vector<int>pref(n);
//         vector<int>prefavg(n);
//         pref[n-1]=nums[n-1];
//         for(int i=n-2; i>=0; i--){
//             pref[i]= nums[i]+pref[i+1];
//         }
//         int c=1;
//         prefavg[n-1]= nums[n-1];
//         for(int i=n-2; i>=0; i--){
//             prefavg[i]=pref[i+1]/c;
//             c++;
//         }
//         for(int i=0; i<n; i++){
//             if(nums[i]>prefavg[i]){
//                 dom++;
//             }
//         } 
//         return dom;
        
//     }
// };




class Solution{
public:
    int dominantIndices(vector<int>& nums){
        int n= nums.size(), sum=accumulate(nums.begin(), nums.end(), 0), cnt=0, curr=0;
        for(int i=0; i<n; i++){
            curr+=nums[i];
            if(n-i-1>0 && (sum-curr)/(n-i-1)<nums[i]){
                cnt++;
            }
        }

        return cnt;
    }
};