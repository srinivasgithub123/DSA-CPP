class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(), potions.end());
        vector<long long> ceill;
        for(int i=0; i<spells.size(); i++){
            ceill.push_back(ceil((double)success/spells[i]));
        }
        for(int i=0; i<spells.size(); i++){
            int idx= lower_bound(potions.begin(), potions.end(), ceill[i]) - potions.begin();
            ans.push_back(potions.size()-idx);
        }
        return ans;
    }
};