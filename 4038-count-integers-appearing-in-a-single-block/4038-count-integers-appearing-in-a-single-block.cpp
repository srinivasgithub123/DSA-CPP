// class Solution {
// public:
//     int countSpecialIntegers(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return 1;
//         }

//         unordered_map<int, int> mp;
//         int ans = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             mp[nums[i]]++;
//         }

//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             int freq = it->second;

//             for (int i = 0; i < nums.size(); i++) {
//                 int cnt = 0;
//                 bool ok = false;

//                 while (i < nums.size() && nums[i] == it->first) {
//                     ok = true;
//                     cnt++;
//                     i++;
//                 }

//                 if (freq == cnt) {
//                     ans++;
//                 }
//                 if(ok==true)
//                 break;
//             }
//         }

//         return ans;
//     }
// };









class Solution{
public:
    int countSpecialIntegers(vector<int>& nums){
        int freq[101]={0}, res=0;
        for(int i=0; i<nums.size(); i++){
            if(i==0 || nums[i]!=nums[i-1]){
                freq[nums[i]]++;
            }
        }

        for(int c: freq){
            if(c==1){
                res++;
            }
        }

        return res;
    }
};