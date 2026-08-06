class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        int j=0, dir= -1;
        vector<string>ans(numRows, "");

        for(int i=0; i<s.size(); i++){
            if(j==numRows-1 || j==0){
                dir= dir*(-1);
            }

            ans[j]+=s[i];

            if(dir==1)j++;
            else j--;
        }

        string res;
        for(auto it: ans){
            res+=it;
        }

        return res;
    }
};