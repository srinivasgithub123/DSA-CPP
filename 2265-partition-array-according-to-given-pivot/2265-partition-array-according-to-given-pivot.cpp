class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>sep;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                sep.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==pivot){
                sep.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pivot){
                sep.push_back(nums[i]);
            }
        }
        return sep;/*
        vector<int> result(nums.size(), 0);
        int left=0, right= nums.size()-1;

        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--){
            if(nums[i]<pivot){
                result[left]=nums[i];
                left++;
            }
            if(nums[i]>pivot){
                result[right]=nums[i];
                right--;
            }
        }
        while(left<=right){
            result[left]=pivot;
            left++;
        }
        
        return result;*/
        
    }
};