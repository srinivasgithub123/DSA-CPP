class Solution {
public:
    bool isPalindromic(string s) {
        string res="";

        for(int i=0; i<s.size(); i++){
            int ascii= s[i];
            res+=bitset<8>(ascii).to_string();
        }
        
        string ans= res;
        reverse(res.begin(), res.end());
        return ans==res;
    }
};