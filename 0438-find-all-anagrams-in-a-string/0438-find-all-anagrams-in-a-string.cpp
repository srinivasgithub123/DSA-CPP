class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int freq1[26]={0};
        int freq2[26]={0};
        for(char ch : p){
            freq1[ch-'a']++;
        }

        int left=0, right=0;
        while(right<s.size()){
            freq2[s[right]-'a']++;
            if(right-left+1==p.size() && equal(freq1, freq1+26, freq2)){
                ans.push_back(left);
                freq2[s[left]-'a']--;
                left++;
            }

            if(right-left+1==p.size() && !equal(freq1, freq1+26, freq2)){
                freq2[s[left]-'a']--;
                left++;
            }
            right++;
        }
    return ans;    
    }
};