// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(t.size()>s.size()){
//             return "";
//         }
//         unordered_map<int, int>mp1;
//         unordered_map<int, int>mp2;
//         for(char ch: t){
//             mp1[ch]++;
//         }

//         int left=0, right=0;
//         while(right<s.size()){
//             if(mp1.count(s[right])){
//                 mp2[s[right]]++;
//             }

//             while(mp1.size()==mp2.size()){
//                 ans= min(ans, right-left+1);
//                 mp2[s[left]]--;
//                 if(mp2[s[left]]==0){
//                     mp2.erase(s[left]);
//                 }
//                 left++;
//             }
//         right++;    
//         }  
//     unordered_map<int, int>mp3;
//     string res="";
//     int i=0, j=0;
//     while(j<s.size()){
//         if(mp1.count(s[j])){
//             mp3[s[j]]++;
//         }
//         if(mp1.size()==mp3.size() && j-i+1==ans){
//             break;
//         }
//     j++;    
        
//     }

//     for(int k=i; k<=j; k++){
//         res=res+s[k];
//     }          
//     }
// };













class Solution{
public:
    string minWindow(string s, string t){
        if(t.size()>s.size())return "";

        unordered_map<char, int>need;
        unordered_map<char, int>wind;
        int required=0, formed=0;
        for(char ch: t){
            need[ch]++;
        }
        required= need.size();
        pair<int, int>ans;
        int minLen=INT_MAX, start=-1;

        int i=0;
        for(int j=0; j<s.size(); j++){
            wind[s[j]]++;
            if(need.count(s[j]) &&wind[s[j]]==need[s[j]]){
                formed++;
            }

            while(formed==required){
                if(j-i+1<minLen){
                    minLen= j-i+1;
                    start=i;
                }
                if(need.count(s[i]) && wind[s[i]]==need[s[i]]){
                    formed--;
                }

                wind[s[i]]--;
                i++;


            }
        }

        if(start==-1)return "";

        return s.substr(start, minLen);
    }
};