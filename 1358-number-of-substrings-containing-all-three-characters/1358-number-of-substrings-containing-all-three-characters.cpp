// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int cnt[3]={0};
//         int left=0, ans=0;

//         for(int right=0; right<s.size(); right++){
//             cnt[s[right]-'a']++;

//             while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
//                 ans+=s.size()-right;
//                 cnt[s[left]-'a']--;
//                 left++;
//             }
//         }
//     return ans;    
        
//     }
// };
















class Solution{
public:
    int numberOfSubstrings(string s){
        int res=0;
        int left=0, right=0;
        vector<int>ans(3, 0);
        while(right<s.size()){
            if(s[right]=='a'){
                ans[0]++;
            }else if(s[right]=='b'){
                ans[1]++;
            }else{
                ans[2]++;
            }

            while(ans[0]>0 && ans[1]>0 && ans[2]>0){
                res= res+s.size()-right;
                if(s[left]=='a'){
                ans[0]--;
            }else if(s[left]=='b'){
                ans[1]--;
            }else{
                ans[2]--;
            }
                
                left++;
            }
        right++;    
        }
    return res;    
    }
};