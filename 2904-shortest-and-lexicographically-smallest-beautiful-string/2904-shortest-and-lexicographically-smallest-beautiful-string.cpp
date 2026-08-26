class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        int left=0, len=INT_MAX;
        int count1=0;
        string ans="";

        for(int right=0; right<s.size(); right++){
            if(s[right]=='1'){
                count1++;
                while(count1==k){
                    if(right-left+1 < len){
                        len= right-left+1;
                        ans= s.substr(left, len);
                    }else if(right-left+1 == len){
                        string str= s.substr(left, len);
                        if(str<ans){
                            ans= str;
                        }  
                    }

                    if(s[left]=='1'){
                        count1--;
                    }

                    left++;
                }
            }

        }

        return ans;
    }
};