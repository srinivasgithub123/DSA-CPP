class Solution {
public:

    bool validK(int k, vector<int>&piles, int h){
        long long hours=0;
        for(auto it: piles){
            hours+=(it+k-1)/k;
        }

        if(hours<=h){
            return true;
        }

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right= *max_element(piles.begin(), piles.end());
        while(left<right){
            int mid= left+(right-left)/2;

            if(validK(mid, piles, h)){
                right= mid;
            }else{
                left= mid+1;
            }
        } 
    return left;    
        
    }
};