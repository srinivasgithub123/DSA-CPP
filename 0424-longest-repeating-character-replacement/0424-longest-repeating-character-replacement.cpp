class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0};
        int i=0, max_freq=0, ans=0;
        for(int j=0; j<s.size(); j++){
            freq[s[j]-'A']++;
            max_freq= max(max_freq, freq[s[j]-'A']);
            int replacements= (j-i+1)- max_freq;
            while(replacements>k){
                freq[s[i]-'A']--;
                i++;
                replacements= (j-i+1)-max_freq;
            }

            if(replacements<=k){
                ans= max(ans, j-i+1);
            }
        }

    return ans;
        
    }
};