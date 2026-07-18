class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min=nums[0], max= nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<min){
                min= nums[i];
            }if(nums[i]>max){
                max= nums[i];
            }
        }

    //     sort(nums.begin(), nums.end());
    //    int min= nums[0];
    //     int max= nums[nums.size()-1];

        while(max!=0){
            int rem= min%max;
            min= max;
            max= rem;
        }
    return min;    
        
    }
};