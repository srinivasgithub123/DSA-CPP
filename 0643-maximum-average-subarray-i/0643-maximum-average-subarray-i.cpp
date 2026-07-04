// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         int maxsum=0, currsum=0;
//         for(int i=0;i<k;i++){
//             currsum+=nums[i];
//         }
//         maxsum=currsum;
//         for(int i=k;i<nums.size();i++){
//             currsum+=nums[i]-nums[i-k];
//             maxsum=max(maxsum, currsum);
//         }
//         return (double)maxsum/k;
//     }
// };





class Solution{
public:
    double findMaxAverage(vector<int>&nums, int k){
        double max_avg= -1e9;
        int left=0, right=0, sum=0;
        while(right<nums.size()){
            sum=sum+nums[right];
            if(right-left+1==k){
                double avg= (double)sum/k;
                max_avg= max(max_avg, avg);
                sum=sum-nums[left];
                left++;
            }
            right++;
        }
    return max_avg;    
    }
};




