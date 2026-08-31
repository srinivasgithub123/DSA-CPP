class Solution {
public:

    long long power(long long x, long long y){
        long long mod = 1e9 + 7;
        long long ans = 1;

        while(y > 0){
            if(y % 2 == 1){
                ans = (ans * x) % mod;
            }

            x = (x * x) % mod;
            y = y / 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        long long mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++){
            int width = nums[i] % 10;

            long long di = nums[i] / 10;

            string dii = to_string(di);
            string x = dii.substr(0, width);
            string y = dii.substr(width);

            int xi = stoi(x);
            int yi = stoi(y);

            sum = (sum + power(xi, yi)) % mod;
        }

        return sum;
    }
};