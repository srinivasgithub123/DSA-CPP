class Solution {
public:
    int firstUniqChar(string s) {
        // queue<int> q;

        // for(int i=0; i<s.size(); i++) {
        //     freq[s[i]]++;
        //     if(freq[s[i]] == 1) {   // first time seeing this character
        //         q.push(i);
        //     }
        //     // Remove all indices from the front which are now repeated
        //     while(!q.empty() && freq[s[q.front()]] > 1) {
        //         q.pop();
        //     }
        // }

        // return q.empty() ? -1 : q.front();
        unordered_map<char,int> freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
