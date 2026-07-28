class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        int mid = -1;
        if (n % 2 == 1) {
            mid = n / 2;
        }

        // Count frequencies (excluding middle if odd)
        for (int i = 0; i < n; i++) {
            if (i == mid) continue;
            freq[s[i] - 'a']++;
        }

        int ptr = 0; // points to the smallest available character

        for (int i = 0; i < n / 2; i++) {

            // Find the next available character
            while (ptr < 26 && freq[ptr] == 0)
                ptr++;

            char ch = 'a' + ptr;

            s[i] = ch;
            s[n - 1 - i] = ch;

            freq[ptr] -= 2;
        }

        return s;
    }
};









// class Solution{
// public:
//     string smallestPalindrome(string s){
//         string first= s.substr(0, s.size()/2);
//         sort(first.begin(), first.end());
//         string second= first;
//         reverse(second.begin(), second.end());
//         if(s.size()%2==0)return first+second;
//         return first+s[s.size()/2]+second;
//     }
// };