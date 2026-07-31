class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8){
            return word.size();
        }

        int count=1, ans=0, i=0;
        while(i<word.size()){
            string str= word.substr(i, 8);
            ans+=str.size()*count;
            count++;
            i=i+8;
        }
    return ans;    
    }
};