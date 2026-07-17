// // class Solution {
// // public:
// //     bool checkSubarraySum(vector<int>& nums, int k) {
// //         unordered_map<int, int>remainderidx;
// //         remainderidx[0]=-1;
// //         int ps=0;

// //         for(int i=0; i<nums.size(); i++){
// //             ps+=nums[i];

// //             int rem=ps%k;

// //             if(rem<0) rem+=k;
// //             if(remainderidx.find(rem)!=remainderidx.end()){
// //                 if(i-remainderidx[rem]>=2)
// //                 return true;
// //             }
// //             else{
// //                 remainderidx[rem]=i;
// //             }
// //         }
// //         return false;
        
// //     }
// // };















// class Solution{
// public:
//     bool checkSubarraySum(vector<int>& nums, int k){
//         for(int i=0; i<nums.size(); i++){
//             int sum=nums[i];
//             for(int j=i+1; j<nums.size(); j++){
//                 sum+=nums[j];
//                 if(sum%k==0){
//                     return true;
//                 }
//             }
//         }
//     return false;    
//     }
// };








class Solution{
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        unordered_map<int, int>remainderIndex;
        remainderIndex[0]=-1;
        int sum=0;
       for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        int rem= sum%k;
        if(remainderIndex.find(rem)==remainderIndex.end()){
            remainderIndex[rem]=i;
        }else if(i-remainderIndex[rem]>=2){
            return true;
        }
       }
    return false;    
    }
};