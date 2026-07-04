// class Solution {
// public:
//     bool isVowel(char c) {
//         return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
//     }

//     int maxVowels(string s, int k) {
//         int count = 0, maxvowel = 0;

//         // First window
//         for (int i = 0; i < k; i++) {
//             if (isVowel(s[i])) count++;
//         }
//         maxvowel = count;

//         // Slide the window
//         for (int i = k; i < s.size(); i++) {
//             if (isVowel(s[i])) count++;       // incoming
//             if (isVowel(s[i - k])) count--;   // outgoing
//             maxvowel = max(maxvowel, count);
//         }

//         return maxvowel;
//     }
// };












class Solution{
public:
    int maxVowels(string s, int k){
        int max_vowels= 0, vowel_count=0;
        int left=0, right=0;
        while(right<s.size()){
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u'){
                vowel_count++;
            }

            if(right-left+1==k){
                max_vowels= max(max_vowels, vowel_count);
                if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u')
                vowel_count--;
                left++;
                
            }
        right++;    
        }
    return max_vowels;    
    }
};