// // class Solution {
// // public:
// //     int maxNumberOfBalloons(string text) {
// //         unordered_map<char, int>mp;
// //         for(int i=0; i<text.size(); i++){
// //             if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n')
// //                 mp[text[i]]++;
// //         }

// //         mp['l']= mp['l']/2;
// //         mp['o']= mp['o']/2;

// //         int ans= INT_MAX;
// //         return min({
// //     mp['b'],
// //     mp['a'],
// //     mp['l'],
// //     mp['o'],
// //     mp['n']
// // });    


        
// //     }
// // };

// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         int b = 0, a = 0, l = 0, o = 0, n = 0;

//         for (char c : text) {
//             if (c == 'b') b++;
//             else if (c == 'a') a++;
//             else if (c == 'l') l++;
//             else if (c == 'o') o++;
//             else if (c == 'n') n++;
//         }

//         return min({b, a, l / 2, o / 2, n});
//     }
// };










class Solution{
public:
    int maxNumberOfBalloons(string text){
        unordered_map<char, int>mp;
        for(char ch: text){
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n'){
                mp[ch]++;
            }
        }

        return min({mp['a'], mp['b'], mp['l']/2, mp['o']/2, mp['n']});
    }
};