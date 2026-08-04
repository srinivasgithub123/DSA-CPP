// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         vector<int>ans;
//         int small= *min_element(nums.begin(), nums.end());
//         int big= *max_element(nums.begin(), nums.end());
//         unordered_set<int>st(nums.begin(), nums.end());

//         for(int i=small; i<=big; i++){
//             if(st.find(i)==st.end()){
//                 ans.push_back(i);
//             }
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };









class Solution{
public:
    vector<int>findMissingElements(vector<int>& nums){
        vector<bool>vis(100, false);
        for(int i=0; i<nums.size(); i++){
            vis[nums[i]]=true;
        }
        vector<int>ans;
        int small= *min_element(nums.begin(), nums.end());
        int big= *max_element(nums.begin(), nums.end());
        for(int i=small; i<=big; i++){
            if(vis[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};