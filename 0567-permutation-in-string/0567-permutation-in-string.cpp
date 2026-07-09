// class Solution {
// public:
//     bool isFreqsame(int Freq1[], int Freq2[]){
//         for(int i=0;i<26;i++){
//             if(Freq1[i]!=Freq2[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool checkInclusion(string s1, string s2) {
//         int freq[26]={0};

//         for(int i=0;i<s1.length();i++){
//             freq[s1[i]-'a']++;
//         }
        
//         int windsize=s1.length();

//         for(int i=0;i<s2.length();i++){
//             int windidx=0,idx=i;
//             int windFreq[26]={0};
           
//            while(windidx<windsize && idx<s2.length()){
//                 windFreq[s2[idx]-'a']++;
//                 windidx++;idx++;
//             }
//             if(isFreqsame(freq, windFreq)){
//                 return true;
//             }
//         }
//         return false;
        
//     }
//};

// class Solution{
// public:
//     bool checkInclusion(string s1, string s2){
//         if(s1.size()>s2.size())return false;
//         int freq1[26]={0};
//         int freq2[26]={0};
//         for(int i=0; i<s1.size(); i++){
//             freq1[s1[i]-'a']++;
//         }

//         int left=0;
//         int right=0;
//         while(right<s2.size() && left<=s2.size()-s1.size()+1){
//             freq2[s2[right]-'a']++;
//             if(right-left+1>s1.size()){
//                 freq2[s2[left]-'a']--;
//                 left++;
//             }
//             if(right-left+1==s1.size() && equal(freq1, freq1+26, freq2)){
//                 return true;
//             }
//             right++;
//         }

//     return false;    
//     }
// };








class Solution{
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size()>s2.size()){
            return false;
        }

        int freq1[26]={0};
        int freq2[26]={0};
        for(char ch: s1){
            freq1[ch-'a']++;
        }

        int left=0, right=0;
        while(right<s2.size()){
            freq2[s2[right]-'a']++;
            if(right-left+1==s1.size() && equal(freq1, freq1+26, freq2)){
                return true;
            }

            if(right-left+1==s1.size() && !equal(freq1, freq1+26, freq2)){
                freq2[s2[left]-'a']--;
                left++;

            }
        right++;    
        }
    return false;    
    }
};