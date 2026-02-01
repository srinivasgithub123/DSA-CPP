class Solution {
public:
    int countMonobit(int n) {
        
        int count=1;
        for(int i=1; i<=n; i++){
            if((i&(i+1))==0){
                count++;
            }
            
        }

        return count;
        
    }
};