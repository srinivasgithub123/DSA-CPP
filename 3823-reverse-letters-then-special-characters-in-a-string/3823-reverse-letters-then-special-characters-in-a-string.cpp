class Solution {
public:
    string reverseByType(string s) {
        stack<char>st1;
        stack<char>st2;
        for(char ch: s){
            if(ch>='a' && ch<='z'){
                st1.push(ch);
            }else{
                st2.push(ch);
            }
        }
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                ans+=st1.top();
                st1.pop();
            }else{
                ans+=st2.top();
                st2.pop();
            }
        }

        return ans;
        
    }
};

// class Solution {
// public:
//     string reverseByType(string s) {
//         int left= 0;
//         int right= s.size()-1;

//         while(left<right){
//             while(left<s.size() && !isalpha(s[left])){
//                 left++;
//             }

//             while(right>=0 && !isalpha(s[right])){
//                 right--;
//             }

//             if(left<right){
//                 swap(s[left], s[right]);
//                 left++;
//                 right--;
//             }
//         }

//          left= 0;
//          right= s.size()-1;

//         while(left<right){
//             while(left<s.size() && isalpha(s[left])){
//                 left++;
//             }

//             while(right>=0 && isalpha(s[right])){
//                 right--;
//             }

//             if(left<right){
//                 swap(s[left], s[right]);
//                 left++;
//                 right--;
//             }
//         } 

//         return s;
//     }};