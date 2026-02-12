class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            unordered_map<char, int>mp;
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++;
                int freq= mp.begin()->second;
                bool ok= true;

                for(auto it: mp){
                    if(it.second!=freq){
                        ok= false;
                        break;
                    }
                } 

                if(ok){
                    ans= max(ans, j-i+1);
                }
            }
        }
    return ans;    
    }
};