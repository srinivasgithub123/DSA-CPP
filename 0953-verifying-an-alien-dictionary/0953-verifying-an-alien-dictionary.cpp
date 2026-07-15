class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>pos(26);
        for(int i=0; i<order.size(); i++){
            pos[order[i]-'a']=i;
        }
        for(int i=0; i<words.size()-1; i++){
            string s1= words[i];
            string s2= words[i+1];
            int len= min(s1.size(), s2.size());
            bool foundiff=false;

            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr]!=s2[ptr]){
                    foundiff=true;
                    if(pos[s1[ptr]-'a'] > pos[s2[ptr]-'a']){
                        return false;
                    }
                break;   
                }
            } 
            if(foundiff==false && s1.size()>s2.size()){
                return false;   
            }
            
        }
    return true;    
    }
};