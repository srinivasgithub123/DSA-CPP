class Solution {
public:
    int vowelConsonantScore(string s) {
        int score=0, v=0, c=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    v++;
                }else{
                    c++;
                }
            }
        }

        if(c>0){
            score= floor(v/c);
        }else{
            return score;
        }

        return score;
        
    }
};