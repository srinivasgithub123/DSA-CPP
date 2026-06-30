// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> charSet;
//         int left = 0, right = 0, maxLen = 0;

//         while (right < s.length()) {
//             if (charSet.find(s[right]) == charSet.end()) {
//                 charSet.insert(s[right]);
//                 maxLen = max(maxLen, right - left + 1);
//                 right++;
//             } else {
//                 charSet.erase(s[left]);
//                 left++;
//             }
//         }

//         return maxLen;
//     }
// };












class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int ans=0;
        unordered_set<char>st;
        int left=0;

        for(int right=0; right<s.size(); right++){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
            }else{
                while(st.count(s[right])){
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[right]);
            }
            ans= max(ans, right-left+1);
        }

    return ans;    
    }
};