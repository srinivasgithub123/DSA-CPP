class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0, cap = 0;

        for (int i = 0; i < word.size(); i++) {
            int ascii = word[i];   // <-- THIS is the change you asked

            if (ascii >= 65 && ascii <= 90) {
                cap++;
            } else if (ascii >= 97 && ascii <= 122) {
                small++;
            }
        }

        if (small == word.size() || cap == word.size()) {
            return true;
        } 
        else if (small == word.size() - 1 && cap == 1 && word[0] >= 65 && word[0] <= 90) {
            return true;
        }

        return false;
    }
};
