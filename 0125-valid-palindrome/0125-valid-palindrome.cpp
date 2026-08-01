// class Solution {
// public:
// bool isAlphanum(char ch){
//             if((ch>='0' && ch<='9')||(tolower(ch)>='a' && tolower(ch)<='z'))
//             return true;
//             return false;
//         }
//     bool isPalindrome(string s) {
        
//         int st=0,end=s.length()-1;
//         while(st<end){
//             if(!isAlphanum(s[st])){
//                 st++;continue;
//             }
//             if(!isAlphanum(s[end])){
//                 end--;
//                 continue;
//             }
//             if(s[st]!=s[end])
//             return false;
//         }
//         return true;
//     }
// };














// class Solution{
// public:
//     bool isPalindrome(string s){
//         transform(s.begin(), s.end(), s.begin(), ::tolower);
//         string temp="";
//         for(auto it: s){
//             if((it>='a' && it<='z') || (it>='0' && it<='9')){
//                 temp+=it;
//             }
//         }
//          string ans="";
//          for(int i=temp.size()-1; i>=0; i--){
//             ans+=temp[i];
//          }

//          return temp==ans;
//     }
// };













class Solution{
public:

    bool isalphanumeric(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s){
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left=0, right=s.size()-1;
        while(left<right){
            if(!isalphanumeric(s[left])){
                left++;
                continue;
            }
            if(!isalphanumeric(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }else{
                return false;
            }
        } 
    return true;    
    }
};