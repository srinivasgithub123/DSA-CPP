class Solution {
public:
    int residuePrefixes(string s) {
        set<char>S;
        int residue=0, len=0;
        for(char ch : s){
            len++;
            S.insert(ch);
            if(S.size()==len%3){
                residue++;
            }
        }
        return residue;
        
    }
};