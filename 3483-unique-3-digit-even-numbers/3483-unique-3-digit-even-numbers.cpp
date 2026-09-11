class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;

        for(int i = 0; i < digits.size(); i++) {
            for(int j = 0; j < digits.size(); j++) {
                for(int k = 0; k < digits.size(); k++) {

                    if(i != j && i != k && j != k) {

                        // First digit cannot be 0
                        if(digits[i] == 0)
                            continue;

                        int num = digits[i] * 100 +
                                  digits[j] * 10 +
                                  digits[k];

                        // Last digit must be even
                        if(num % 2 == 0) {
                            nums.insert(num);
                        }
                    }
                }
            }
        }

        return nums.size();
    }
};