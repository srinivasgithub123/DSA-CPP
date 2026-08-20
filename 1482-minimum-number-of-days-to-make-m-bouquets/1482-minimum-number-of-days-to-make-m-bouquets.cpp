class Solution {
public:

    bool valid(int day, vector<int>& bloomDay, int m, int k){
        int bouqet=0, adj=0;
        
        for(int i=0; i<bloomDay.size(); i++){
           if(bloomDay[i]<=day){
                adj++;
                if(adj==k){
                    bouqet++;
                    adj=0;
                }
           } 
            else if(bloomDay[i]>day){
                adj=0;
            }
        }
    return bouqet>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)
        return -1;

        int left= *min_element(bloomDay.begin(), bloomDay.end());
        int right= *max_element(bloomDay.begin(), bloomDay.end());

        while(left<right){
            int mid= left+(right-left)/2;

            if(valid(mid, bloomDay, m, k)){
                right= mid;
            }else{
                left= mid+1;
            }
        }

        return left;
        
    }
};