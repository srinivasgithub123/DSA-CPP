class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        for(int i=0; i<text.size(); i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n')
                mp[text[i]]++;
        }

        mp['l']= mp['l']/2;
        mp['o']= mp['o']/2;

        int ans= INT_MAX;
        return min({
    mp['b'],
    mp['a'],
    mp['l'],
    mp['o'],
    mp['n']
});    


        
    }
};