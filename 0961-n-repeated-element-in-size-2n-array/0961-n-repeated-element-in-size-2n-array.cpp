class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    //     unordered_map<int, int>mp;
    //     int n= nums.size()/2;
    //     for(int i=0; i<nums.size(); i++){
    //         mp[nums[i]]++;
    //     }
    //     for(auto it=mp.begin(); it!=mp.end(); it++){
    //         if(it->second==n){
    //             return it->first;
    //         }
    //     }
    //    return -1; 

    //optimized approach

    unordered_set<int>seen;
    for(int i=0; i<nums.size(); i++){
        if(seen.find(nums[i])!=seen.end()){
            return nums[i];
        }
        seen.insert(nums[i]);
    }

    return -1;
    }
};