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