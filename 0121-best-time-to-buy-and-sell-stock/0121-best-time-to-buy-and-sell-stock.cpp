// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mp=0,bb=prices[0];
//         for(int i=1;i<prices.size();i++){
//             if(prices[i]>bb){
//                 mp=max(mp,prices[i]-bb);
//             }
//             bb=min(bb,prices[i]);
//         }
//            return mp;
//     }
// };














class Solution{
public:
    int maxProfit(vector<int>& nums){
        int max_profit= 0, min= nums[0];
       
       for(int i=1; i<nums.size(); i++){
        if(nums[i]>min){
            max_profit= max(max_profit, nums[i]- min);
        }else if(nums[i]<min){
            min= nums[i];
        }
       }
        return max_profit;
    }
};