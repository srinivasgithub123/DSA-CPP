// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<char, int>mp;
//         for(auto it: word){
//             mp[it]++;
//         }

//         vector<int>freq;
//         for(auto it: mp){
//             freq.push_back(it.second);
//         }

//         sort(freq.begin(), freq.end(), greater<int>());

//         int c=0,i=1;
//         int ans=0;
//         for(auto it: freq){
//             c++;
//             ans=ans+(it * i);
//             if(c==8*i){
//                 i++;
//             }
//         }
//     return ans;    
        
//     }
// };
















class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};

        // Count frequency of each character
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq, freq + 26, greater<int>());

        int ans = 0;

        // Assign push costs
        for (int i = 0; i < 26; i++) {
            
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};