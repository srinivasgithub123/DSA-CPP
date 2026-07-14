// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         vector<int>left;
//         vector<int>right;
//         int s=0;
//         for(int i=0; i<nums.size(); i++){
//             s+=nums[i];
//             left.push_back(s);
//         }
//         s=0;
//         for(int j=nums.size()-1; j>=0; j--){
//             s+=nums[j];
//             right.push_back(s);
//         }
//         reverse(right.begin(), right.end());
//         for(int i=0; i<nums.size(); i++){
//             if(left[i]==right[i])
//             return i;
//         }
//         return -1;
//     }
// };













class Solution{
public:
    int pivotIndex(vector<int>& nums){
        vector<int>ps(nums.size());
        vector<int>ss(nums.size());
        ps[0]=nums[0];
        ss[nums.size()-1]=nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++){
            ps[i]= ps[i-1]+nums[i];
        }  

        for(int i=nums.size()-2; i>=0; i--){
            ss[i]=ss[i+1]+nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            if(ps[i]-ss[i]==0){
                return i;
            }
        }
    return -1;    
    }
};