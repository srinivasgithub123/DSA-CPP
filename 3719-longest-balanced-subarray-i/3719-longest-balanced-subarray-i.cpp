class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            unordered_set<int> setEven, setOdd;

            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0)
                    setEven.insert(nums[j]);
                else
                    setOdd.insert(nums[j]);

                if(setEven.size() == setOdd.size()){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
