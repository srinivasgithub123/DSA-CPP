class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for(int c: s){
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
    c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
        v.push_back(c);
    }

        }

        sort(v.begin(), v.end());
        int i=0;
        for (int j = 0; j < s.size(); j++) {
        char c = s[j];
    // check if c is a vowel
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        s[j]=v[i];
        i++;
    }
}
   return s;     
    }
};