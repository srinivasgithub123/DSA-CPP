class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        // int count=0, n= nums.size();
        // for(int i=0; i<n; i++){
        //     long long sum=0;
        //     for(int j=i; j<n; j++){
        //         sum=sum+nums[j];
        //         for(int k=i; k<=j; k++){
        //             if(nums[k]==sum){
        //                 count++;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return count;

        int count=0;

        for(int i=0; i<nums.size(); i++){
            int sum=0;
            set<int>seen;
            for(int j=i; j<nums.size(); j++){
                sum=sum+nums[j];
                seen.insert(nums[j]);
                if(seen.find(sum)!=seen.end()){
                    count++;
                }
            }
        }

        return count;
    }
};